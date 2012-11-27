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


#include "keysticker.h"


KeySticker::KeySticker(QGraphicsItem *parent)
    : QGraphicsWidget(parent)
{}

KeySticker::KeySticker(int id, QString text, int directIputID, int time, bool down, X::KeyType type,  QGraphicsItem *parent)
    : QGraphicsWidget(parent)
{
    m_id = id;
    m_keyDI=directIputID;
    m_keyTime=time;
    m_keyDown=down;
    m_keyType=type;
    m_selected=false;
    formatKeyText(text,type);
}

//METHODE//METHODE//METHODE//METHODE//METHODE//METHODE//METHODE
int KeySticker::id(){
    return m_id;
}

int KeySticker::keyDI(){
    return m_keyDI;
}

void KeySticker::setKeyDI(int di){
    m_keyDI=di;
}


int KeySticker::keyTime(){
    return m_keyTime;
}

void KeySticker::setKeyTime(int t){
    m_keyTime=t;
}

int KeySticker::selected(){
    return m_selected;
}

void KeySticker::setSelected(int b){
    m_selected=b;
}

X::KeyType KeySticker::keyType(){
    return m_keyType;
}

void KeySticker::setKeyType(X::KeyType type){
    m_keyType=type;
}

bool KeySticker::keyDown(){
    return m_keyDown;
}

void KeySticker::formatKeyText(QString text,X::KeyType type){
    QStringList keylist = text.split(" ");
    switch(type){
        default:
        case X::keyDefault:
            if(keylist.length()==2){
                m_keyText[0]=keylist[0];
                m_keyText[1]=keylist[1];
            }
            else{
                m_keyText[0]=text;
                m_keyText[1]="";
            }
            break;
        case X::keyImg:
            m_keyText[0]=text;
            m_keyText[1]="";
            break;
        case X::keyText:
            if(keylist.length()>1){
                m_keyText[0]=keylist[0];
                m_keyText[1]=keylist[1];
            }
            else {
                m_keyText[0]=text;
                m_keyText[1]="";
            }
            break;
     }
}



//SURCHARGE//SURCHARGE//SURCHARGE//SURCHARGE//SURCHARGE//SURCHARGE
void KeySticker::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QFont key("Tohama", 14);
    QFont keytext("Tohama", 8);

    if(m_keyType!=X::keyMouse)painter->drawImage(0,0,QImage(IMG+"x6key.png"));
    if(m_selected==2){
        painter->setPen(QColor(255,255,0));
        painter->drawRect(0,0,STIKER_SIZE-1,STIKER_SIZE-1);
    }
    painter->setPen(QColor(255,0,0));
    if(m_selected==1)
        painter->drawRect(0,0,STIKER_SIZE-1,STIKER_SIZE-1);

    switch(m_keyType){
    default:
    case X::keyDefault:
        painter->setFont(key);
        painter->drawText(19,23, m_keyText[0]);
        painter->drawText(19,42, m_keyText[1]);
        break;
    case X::keyMouse:
        painter->drawImage(boundingRect(),QImage(IMG+m_keyText[0]));
        break;
    case X::keyImg:
        painter->drawImage(16,10,QImage(IMG+m_keyText[0]));
        break;
    case X::keyText:
        painter->setFont(keytext);
        if(m_keyText[1].isEmpty())painter->drawText(0,0,64,50, Qt::AlignCenter, m_keyText[0]);
        else {
            painter->drawText(0,12,64,10, Qt::AlignCenter,m_keyText[0]);
            painter->drawText(0,30,64,10, Qt::AlignCenter,m_keyText[1]);
        }
    }

    if(m_id>=0){
        painter->drawImage(0,0,QImage(IMG+((m_keyDown) ? "key_down.png" : "key_up.png")));
        painter->setFont(keytext);
        painter->setPen(QColor(Qt::white));
        painter->drawText(0,0,56,63, Qt::AlignRight|Qt::AlignBottom, QString::number(m_keyTime));
    }
    //debug id
    //painter->drawText(boundingRect(), Qt::AlignLeft|Qt::AlignBottom, QString::number(m_id));
}

void KeySticker::mousePressEvent (QGraphicsSceneMouseEvent *event){
    if(m_id>=0){
        m_selected=true;
        emit clicked(m_id);
        //update(boundingRect());
    }
}

//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT//SLOT
void KeySticker::updateKeyTime(int time){
    setKeyTime(time);
    update(boundingRect());
}


