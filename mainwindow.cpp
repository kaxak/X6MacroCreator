/*
Copyright © ROCHE Emmanuel, 2012

git@kaxak.net

Ce logiciel est un programme informatique servant à créer et éditer des macros pour clavier.

Ce logiciel est régi par la licence CeCILL soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL, et que vous en avez accepté les
termes.
---------------------------------------------------------------------------------------------
Copyright © ROCHE Emmanuel, 2012

git@kaxak.net

This software is a computer program whose purpose is to create and to edit keyboard macros.

This software is governed by the CeCILL license under French law and
abiding by the rules of distribution of free software.  You can  use,
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability.

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or
data to be ensured and,  more generally, to use and operate it in the
same conditions as regards security.

The fact that you are presently reading this means that you have had
knowledge of the CeCILL license and that you accept its terms.
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //basic init
    m_idCounter=0;
    m_idActive=0;
    m_file="";
    m_keyMap = new KeyMap;
    m_saved = true;
    m_homeUser = QDesktopServices::storageLocation (QDesktopServices::DocumentsLocation);

    //graphics parts
    m_scene = new QGraphicsScene;
    m_scene->setBackgroundBrush(QColor(100,100,100));
    m_sceneKeyEdit = new QGraphicsScene;
    m_sceneKeyEdit->setBackgroundBrush(QColor(100,100,100));
    m_keyEditor = new KeySticker(-1, "", 0, 10, false,X::keyText);
    m_keyEditor->setPreferredSize(STIKER_SIZE,STIKER_SIZE);

    ui->macroKeyView->setScene(m_scene);
    ui->macroKeyView->installEventFilter(this);
    ui->graphicsViewKeyEditor->setScene(m_sceneKeyEdit);
    ui->macroKeyView->setFocus();

    //directinput
    HWND hw = this->winId();
    HINSTANCE hi = (HINSTANCE)GetWindowLong(hw, GWL_HINSTANCE);
    m_directInput = new Input;
    m_directInput->init(hi, hw);
    for(int i=0;i<256;i++){
        m_keyStat[i]=false;
    }

    //other
    updateWindowTitle();
    QTimer *directInputTimer = new QTimer(this);
    directInputTimer->start(10);

    //CONNECT//CONNECT//CONNECT//CONNECT//CONNECT
    QObject::connect(ui->macroRepeat,SIGNAL(toggled(bool)),this,SLOT(updateXml()));
    QObject::connect(directInputTimer,SIGNAL(timeout()),this,SLOT(checkDirectInput()));
    QObject::connect(ui->pushButtonKeyEditorOff,SIGNAL(clicked(bool)),this,SLOT(endEditKey()));
    QObject::connect(ui->pushButtonEraseMacro,SIGNAL(clicked()),this,SLOT(eraseMacro()));
    QObject::connect(ui->pushButtonEraseKey,SIGNAL(clicked()),this,SLOT(eraseKey()));
    //action (menu fichier)
    QObject::connect(ui->actionNouveau,SIGNAL(triggered()),this,SLOT(newMacro()));//new
    QObject::connect(ui->actionOuvrir,SIGNAL(triggered()),this,SLOT(openMacro()));//open
    QObject::connect(ui->actionEnregistrer,SIGNAL(triggered()),this,SLOT(saveMacro()));//save
    QObject::connect(ui->actionEnregistrer_sous,SIGNAL(triggered()),this,SLOT(saveMacroUnder()));//save under
    QObject::connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(closeControl()));//close
    //action (menu edition)
    QObject::connect(ui->actionEffacer_la_macro,SIGNAL(triggered()),this,SLOT(eraseMacro()));
    //action (menu ?)
    QObject::connect(ui->actionAbout_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    //emulation souris
    QObject::connect(ui->pushButtonMouse1,SIGNAL(toggled(bool)),this,SLOT(addmouse1(bool)));
    QObject::connect(ui->pushButtonMouse2,SIGNAL(toggled(bool)),this,SLOT(addmouse2(bool)));
    QObject::connect(ui->pushButtonMouse3,SIGNAL(toggled(bool)),this,SLOT(addmouse3(bool)));
    QObject::connect(ui->pushButtonMouse4,SIGNAL(toggled(bool)),this,SLOT(addmouse4(bool)));
    QObject::connect(ui->pushButtonMouse5,SIGNAL(toggled(bool)),this,SLOT(addmouse5(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
    while(m_macroKeyList.size()){
        delete m_macroKeyList[m_macroKeyList.size()-1];
        m_macroKeyList.pop_back();
    }
}

//METHOD//METHOD//METHOD//METHOD//METHOD//METHOD//METHOD//METHOD//METHOD//METHOD
void MainWindow::addMacroKey(int id,bool down){
    //key sticker
    int time=ui->spinBoxDefaultTime->value();
    KeySticker *tmp = new KeySticker(m_idCounter, m_keyMap->toSticker(id), id, time, down, m_keyMap->type(id));
    QObject::connect(tmp,SIGNAL(clicked(int)),this,SLOT(editKey(int)));
    tmp->setPreferredSize(STIKER_SIZE,STIKER_SIZE);
    tmp->setPos(m_idCounter%(ui->macroKeyView->width()/STIKER_SIZE)*STIKER_SIZE,m_idCounter/(ui->macroKeyView->width()/STIKER_SIZE)*STIKER_SIZE);
    m_scene->addItem(tmp);
    m_macroKeyList.push_back(tmp);
    m_idCounter++;
    //key xml
    updateXml();
    m_saved = false;
}

void MainWindow::updateMacroKeys(int id){
    m_macroKeyList[m_idActive]->formatKeyText(m_keyMap->toSticker(id),m_keyMap->type(id));
    m_macroKeyList[m_idActive]->setKeyDI(id);
    m_macroKeyList[m_idActive]->setKeyType(m_keyMap->type(id));
    m_macroKeyList[m_idActiveSecond]->formatKeyText(m_keyMap->toSticker(id),m_keyMap->type(id));
    m_macroKeyList[m_idActiveSecond]->setKeyDI(id);
    m_macroKeyList[m_idActiveSecond]->setKeyType(m_keyMap->type(id));
    ui->macroKeyView->update();

    m_keyEditor->setKeyType(m_macroKeyList[m_idActive]->keyType());             //maj TYPE
    m_keyEditor->formatKeyText(                                                         //maj TEXT
                m_keyMap->toSticker(m_macroKeyList[m_idActive]->keyDI()),
                m_macroKeyList[m_idActive]->keyType());
    m_keyEditor->update(m_keyEditor->boundingRect());
    updateXml();
    m_saved=false;
}

void MainWindow::updateWindowTitle(){
    setWindowTitle(QString((m_file.isEmpty())?tr("SansNom.mhm"):m_file.split("/").last())+" - "+windowTitle().split(" - ").last());
}

//SURCHARGE//SURCHARGE//SURCHARGE//SURCHARGE//SURCHARGE//SURCHARGE//SURCHARGE
bool MainWindow::eventFilter(QObject *o, QEvent *e){
    if (o ==  ui->macroKeyView){
        switch(e->type()){
            case QEvent::KeyPress:
                return true;
                break;
            case QEvent::KeyRelease:
                return true;
                break;
            case QEvent::MouseButtonPress:
                return true;
                break;
            case QEvent::MouseButtonRelease:
                return true;
                break;
            case QEvent::Shortcut:
                return true;
                break;
            case QEvent::Close:
                return true;
                break;
            case QEvent::FocusOut:
                ui->macroKeyView->setFocus();
                return true;
                break;
            case QEvent::FocusIn:
                ui->macroKeyView->grabKeyboard();
                return true;
                break;
            default:
                return false;
        }
    }
    return false;
}

void MainWindow::closeEvent (QCloseEvent * e){
    e->ignore();
    if(!m_keyStat[DIK_LMENU])closeControl();
}

//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT
void MainWindow::editKey(int id){
    //efface tout les m_selected des keyStickers
    for(int i=0;i<m_macroKeyList.size();i++)
        m_macroKeyList[i]->setSelected(0);
    m_macroKeyList[id]->setSelected(1);
    //mise a jour des connexions
    ui->spinBoxKeyEditor->disconnect();
    QObject::connect(ui->spinBoxKeyEditor,SIGNAL(valueChanged(int)),m_macroKeyList[id],SLOT(updateKeyTime(int)));
    QObject::connect(ui->spinBoxKeyEditor,SIGNAL(valueChanged(int)),this,SLOT(updateXml()));
    //active le keyEditor
    if(!ui->groupKeyEditor->isEnabled())m_sceneKeyEdit->addItem(m_keyEditor);
    ui->groupKeyEditor->setEnabled(true);
    //mise a jour du keyEditor
    m_keyEditor->setKeyType(m_macroKeyList[id]->keyType());             //maj TYPE
    m_keyEditor->formatKeyText(                                                         //maj TEXT
                m_keyMap->toSticker(m_macroKeyList[id]->keyDI()),
                m_macroKeyList[id]->keyType());
    ui->spinBoxKeyEditor->setValue(m_macroKeyList[id]->keyTime());      //maj SPINBOX TIME

    //2eme selection
    int i(id);
    if(m_macroKeyList[id]->keyDown()){
        i++;
        while(m_macroKeyList[i]->keyDI()!=m_macroKeyList[id]->keyDI() && i<m_macroKeyList.size()){
            i++;
        }
        m_macroKeyList[i]->setSelected(2);
    }
    else{
        i--;
        while(m_macroKeyList[i]->keyDI()!=m_macroKeyList[id]->keyDI() && i>=0){
            i--;
        }
        m_macroKeyList[i]->setSelected(2);
    }
    //actualisation des view
    m_keyEditor->update(m_keyEditor->boundingRect());
    ui->macroKeyView->update();
    //mise a jour m_idActive
    m_idActive=id;
    m_idActiveSecond=i;
}

void MainWindow::eraseKey(){
    int a,b;
    if(m_idActive>m_idActiveSecond){
        a=m_idActive;
        b=m_idActiveSecond;
    }
    else{
        a=m_idActiveSecond;
        b=m_idActive;
    }
    m_scene->removeItem(m_macroKeyList[a]);
    delete m_macroKeyList[a];
    m_macroKeyList.remove(a);
    m_scene->removeItem(m_macroKeyList[b]);
    delete m_macroKeyList[b];
    m_macroKeyList.remove(b);


    updateXml();
    while(m_macroKeyList.size()){
        m_scene->removeItem(m_macroKeyList[m_macroKeyList.size()-1]);
        delete m_macroKeyList[m_macroKeyList.size()-1];
        m_macroKeyList.pop_back();
    }
    m_idCounter=0;
    updateKeyView(&ui->macroXmlView->toPlainText().split("\n"));
    endEditKey();
}

void MainWindow::endEditKey(){
    for(int i=0;i<m_macroKeyList.size();i++)
        m_macroKeyList[i]->setSelected(0);
    m_idActive=0;
    m_sceneKeyEdit->removeItem(m_keyEditor);
    ui->groupKeyEditor->setEnabled(false);
    ui->macroKeyView->update();
    ui->macroKeyView->setFocus();
}

void MainWindow::checkDirectInput(){
    if(m_directInput->acquire()){
        unsigned char *diKeyStat = m_directInput->keyboardStat();
        for(int i=0;i<256;i++){
            if(!m_keyStat[i] && diKeyStat[i]==128){
                if(ui->macroKeyView->hasFocus()){
                    if(ui->groupKeyEditor->isEnabled()){
                        updateMacroKeys(i);
                    }
                    else{
                        addMacroKey(i,true);
                    }
                m_keyStat[i]=true;
                }
            }
            else if(m_keyStat[i] && diKeyStat[i]==0){
                if(ui->macroKeyView->hasFocus() && !ui->groupKeyEditor->isEnabled())addMacroKey(i,false);
                m_keyStat[i]=false;
            }
        }
    }
}

void MainWindow::updateXml(){
    QString tmpXML("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
    (ui->macroRepeat->isChecked()) ? tmpXML+="<Macro RepeatingMode=\"1\">\n" : tmpXML+="<Macro>\n";

    for(int i=0;i<m_macroKeyList.size();i++){
        (m_macroKeyList[i]->keyType()==X::keyMouse)?
                    tmpXML+="    <MouseEvent Down=\""+QString((m_macroKeyList[i]->keyDown())?"true":"false")+"\">"+QString::number(m_keyMap->toX6(m_macroKeyList[i]->keyDI()))+"</MouseEvent>\n":
            tmpXML+="    <KeyBoardEvent Down=\""+QString((m_macroKeyList[i]->keyDown())?"true":"false")+"\">"+QString::number(m_keyMap->toX6(m_macroKeyList[i]->keyDI()))+"</KeyBoardEvent>\n";
        if(m_macroKeyList[i]->keyTime())tmpXML+="    <DelayEvent>"+QString::number(m_macroKeyList[i]->keyTime())+"</DelayEvent>\n";
    }
    tmpXML+="</Macro>";
    ui->macroXmlView->setPlainText(tmpXML);
}

void MainWindow::updateKeyView(QStringList *xml){
    if(xml->first().contains("<Macro RepeatingMode=\"1\">"))ui->macroRepeat->setChecked(true);
    if(xml->length()>1){
        if(!xml->at(1).contains("</Macro>",Qt::CaseInsensitive)){
            int i(1);
            int backUpDefaulTime(ui->spinBoxDefaultTime->value());
            if(xml->at(1).contains("<DelayEvent>")) i=2;

            for(;i<xml->length()-1;i++){
                bool keyDown(xml->at(i).contains("true", Qt::CaseInsensitive));
                int keyId(0);
                QRegExp rxKey("(\\d+).*(</KeyBoardEvent>)",Qt::CaseInsensitive);
                QRegExp rxMouse("(\\d+).*(</MouseEvent>)",Qt::CaseInsensitive);
                QRegExp rxTime("(\\d+).*(</DelayEvent>)",Qt::CaseInsensitive);
                if(rxKey.indexIn(xml->at(i))!=-1){
                    keyId=rxKey.cap(1).toInt();
                    if(rxTime.indexIn(xml->at(i+1))!=-1){
                        ui->spinBoxDefaultTime->setValue(rxTime.cap(1).toInt());
                        i++;
                    }
                    else{
                        ui->spinBoxDefaultTime->setValue(0);
                    }
                }
                else if(rxMouse.indexIn(xml->at(i))!=-1){
                    keyId=300+rxMouse.cap(1).toInt();
                     if(rxTime.indexIn(xml->at(i+1))!=-1){
                        ui->spinBoxDefaultTime->setValue(rxTime.cap(1).toInt());
                        i++;
                    }
                    else{
                        ui->spinBoxDefaultTime->setValue(0);
                    }
                }
                keyId=m_keyMap->toDI(keyId);
                addMacroKey(keyId,keyDown);
                ui->spinBoxDefaultTime->setValue(backUpDefaulTime);
            }
        }
    }
}

void MainWindow::eraseMacro(){
    if(ui->groupKeyEditor->isEnabled())endEditKey();
    while(m_macroKeyList.size()){
        m_scene->removeItem(m_macroKeyList[m_macroKeyList.size()-1]);
        delete m_macroKeyList[m_macroKeyList.size()-1];
        m_macroKeyList.pop_back();
    }
    m_idCounter=0;
    updateXml();
    m_saved=true;
}

void MainWindow::newMacro(){
    if(!m_saved){
        QMessageBox::StandardButton r = QMessageBox::warning(this,"Attention!","Vous êtes sur le point de perdre les changements apportés à "+m_file.split("/").last()+".\n\nCliquez sur OK pour confirmer.",
                             QMessageBox::Save|QMessageBox::Ok|QMessageBox::Cancel);

        switch(r){
        default:
        case QMessageBox::Cancel:
            return;
            break;
        case QMessageBox::Save:
            saveMacro();
            newMacro();
            return;
            break;
        case QMessageBox::Ok:
            break;
        }
    }
    m_file="";
    updateWindowTitle();
    eraseMacro();


}

void MainWindow::openMacro(){
    newMacro();
    m_file = QFileDialog::getOpenFileName(this,"Ouvrir le fichier",m_homeUser+"\\Microsoft Hardware\\Macros","Macro (*.mhm)");
    QFile file(m_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
             m_file="";
             return;
    }

    updateWindowTitle();
    QTextStream in(&file);
    QStringList *xml = new QStringList(in.readLine());
    if(xml->first().contains("<?xml version=\"1.0\" encoding=\"UTF-8\"?><Macro")){
        while(!in.atEnd()){
          xml->push_back(in.readLine());
    }
    updateKeyView(xml);
    }
    else{
     QMessageBox::critical(this,"Erreur","Fichier non reconnu.");
     m_file="";
    }
}

void MainWindow::saveMacro(){
    if(m_file.isEmpty())
        saveMacroUnder();
    else{
        QFile file(m_file);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            return;
        }
        QTextStream out(&file);
        out << ui->macroXmlView->toPlainText();
        file.close();
        m_saved=true;
    }
}

void MainWindow::saveMacroUnder(){
    m_file = QFileDialog::getSaveFileName(this,"Enregistrez le fichier sous...",m_homeUser+"\\Microsoft Hardware\\Macros","Macro (*.mhm)");
    if(!m_file.isEmpty()){
        updateWindowTitle();
        saveMacro();
    }

}

void MainWindow::closeControl(){
    qApp->exit(0);
}

#define MOUSE(button) void MainWindow::addmouse##button(bool b){\
    if(ui->groupKeyEditor->isEnabled())updateMacroKeys(300+button);\
    else addMacroKey(300+button,b);\
    }
MOUSE(1)
MOUSE(2)
MOUSE(3)
MOUSE(4)
MOUSE(5)



