/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 12. Feb 15:34:51 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionAbout_Qt;
    QAction *actionEnregistrer_sous;
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionNouveau;
    QAction *actionEffacer_la_macro;
    QWidget *centralWidget;
    QPlainTextEdit *macroXmlView;
    QGraphicsView *macroKeyView;
    QGroupBox *groupKeyEditor;
    QSpinBox *spinBoxKeyEditor;
    QGraphicsView *graphicsViewKeyEditor;
    QPushButton *pushButtonKeyEditorOff;
    QPushButton *pushButtonEraseKey;
    QGroupBox *mouseEmulTool;
    QPushButton *pushButtonMouse1;
    QPushButton *pushButtonMouse3;
    QPushButton *pushButtonMouse2;
    QPushButton *pushButtonMouse4;
    QPushButton *pushButtonMouse5;
    QCheckBox *macroRepeat;
    QGroupBox *groupBox;
    QSpinBox *spinBoxDefaultTime;
    QPushButton *pushButtonEraseMacro;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu;
    QMenu *menuEdition;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(920, 552);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionEnregistrer_sous = new QAction(MainWindow);
        actionEnregistrer_sous->setObjectName(QString::fromUtf8("actionEnregistrer_sous"));
        actionOuvrir = new QAction(MainWindow);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        actionEnregistrer = new QAction(MainWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionEffacer_la_macro = new QAction(MainWindow);
        actionEffacer_la_macro->setObjectName(QString::fromUtf8("actionEffacer_la_macro"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        macroXmlView = new QPlainTextEdit(centralWidget);
        macroXmlView->setObjectName(QString::fromUtf8("macroXmlView"));
        macroXmlView->setGeometry(QRect(0, 250, 788, 250));
        macroXmlView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(85, 255, 0);"));
        macroXmlView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        macroXmlView->setUndoRedoEnabled(false);
        macroXmlView->setReadOnly(true);
        macroXmlView->setPlainText(QString::fromUtf8("<?xml version=\"1.0\" encoding=\"UTF-8\"?><Macro>\n"
"</Macro>"));
        macroXmlView->setTextInteractionFlags(Qt::TextSelectableByMouse);
        macroKeyView = new QGraphicsView(centralWidget);
        macroKeyView->setObjectName(QString::fromUtf8("macroKeyView"));
        macroKeyView->setGeometry(QRect(0, 0, 788, 250));
        sizePolicy.setHeightForWidth(macroKeyView->sizePolicy().hasHeightForWidth());
        macroKeyView->setSizePolicy(sizePolicy);
        macroKeyView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(85, 255, 0);"));
        macroKeyView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        macroKeyView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        macroKeyView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupKeyEditor = new QGroupBox(centralWidget);
        groupKeyEditor->setObjectName(QString::fromUtf8("groupKeyEditor"));
        groupKeyEditor->setEnabled(false);
        groupKeyEditor->setGeometry(QRect(800, 30, 111, 181));
        spinBoxKeyEditor = new QSpinBox(groupKeyEditor);
        spinBoxKeyEditor->setObjectName(QString::fromUtf8("spinBoxKeyEditor"));
        spinBoxKeyEditor->setGeometry(QRect(10, 90, 91, 31));
        QFont font;
        font.setPointSize(12);
        spinBoxKeyEditor->setFont(font);
        spinBoxKeyEditor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxKeyEditor->setMinimum(0);
        spinBoxKeyEditor->setMaximum(10000);
        spinBoxKeyEditor->setSingleStep(10);
        graphicsViewKeyEditor = new QGraphicsView(groupKeyEditor);
        graphicsViewKeyEditor->setObjectName(QString::fromUtf8("graphicsViewKeyEditor"));
        graphicsViewKeyEditor->setGeometry(QRect(25, 20, 66, 66));
        graphicsViewKeyEditor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewKeyEditor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewKeyEditor->setAlignment(Qt::AlignCenter);
        pushButtonKeyEditorOff = new QPushButton(groupKeyEditor);
        pushButtonKeyEditorOff->setObjectName(QString::fromUtf8("pushButtonKeyEditorOff"));
        pushButtonKeyEditorOff->setGeometry(QRect(10, 150, 91, 21));
        pushButtonEraseKey = new QPushButton(groupKeyEditor);
        pushButtonEraseKey->setObjectName(QString::fromUtf8("pushButtonEraseKey"));
        pushButtonEraseKey->setGeometry(QRect(10, 130, 91, 20));
        mouseEmulTool = new QGroupBox(centralWidget);
        mouseEmulTool->setObjectName(QString::fromUtf8("mouseEmulTool"));
        mouseEmulTool->setGeometry(QRect(800, 210, 111, 80));
        pushButtonMouse1 = new QPushButton(mouseEmulTool);
        pushButtonMouse1->setObjectName(QString::fromUtf8("pushButtonMouse1"));
        pushButtonMouse1->setGeometry(QRect(10, 20, 31, 23));
        pushButtonMouse1->setCheckable(true);
        pushButtonMouse3 = new QPushButton(mouseEmulTool);
        pushButtonMouse3->setObjectName(QString::fromUtf8("pushButtonMouse3"));
        pushButtonMouse3->setGeometry(QRect(40, 20, 31, 23));
        pushButtonMouse3->setCheckable(true);
        pushButtonMouse2 = new QPushButton(mouseEmulTool);
        pushButtonMouse2->setObjectName(QString::fromUtf8("pushButtonMouse2"));
        pushButtonMouse2->setGeometry(QRect(70, 20, 31, 23));
        pushButtonMouse2->setCheckable(true);
        pushButtonMouse4 = new QPushButton(mouseEmulTool);
        pushButtonMouse4->setObjectName(QString::fromUtf8("pushButtonMouse4"));
        pushButtonMouse4->setGeometry(QRect(10, 50, 31, 23));
        pushButtonMouse4->setCheckable(true);
        pushButtonMouse5 = new QPushButton(mouseEmulTool);
        pushButtonMouse5->setObjectName(QString::fromUtf8("pushButtonMouse5"));
        pushButtonMouse5->setGeometry(QRect(40, 50, 31, 23));
        pushButtonMouse5->setCheckable(true);
        macroRepeat = new QCheckBox(centralWidget);
        macroRepeat->setObjectName(QString::fromUtf8("macroRepeat"));
        macroRepeat->setGeometry(QRect(800, 340, 111, 17));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(800, 290, 111, 51));
        spinBoxDefaultTime = new QSpinBox(groupBox);
        spinBoxDefaultTime->setObjectName(QString::fromUtf8("spinBoxDefaultTime"));
        spinBoxDefaultTime->setGeometry(QRect(10, 20, 91, 22));
        spinBoxDefaultTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxDefaultTime->setMaximum(10000);
        spinBoxDefaultTime->setSingleStep(10);
        spinBoxDefaultTime->setValue(10);
        pushButtonEraseMacro = new QPushButton(centralWidget);
        pushButtonEraseMacro->setObjectName(QString::fromUtf8("pushButtonEraseMacro"));
        pushButtonEraseMacro->setGeometry(QRect(800, 10, 111, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 920, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menu->addAction(actionAbout_Qt);
        menuEdition->addAction(actionEffacer_la_macro);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "X6 Macro", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionEnregistrer_sous->setText(QApplication::translate("MainWindow", "Enregistrer sous...", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("MainWindow", "Ouvrir", 0, QApplication::UnicodeUTF8));
        actionEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        actionNouveau->setText(QApplication::translate("MainWindow", "Nouveau", 0, QApplication::UnicodeUTF8));
        actionEffacer_la_macro->setText(QApplication::translate("MainWindow", "Effacer la macro", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupKeyEditor->setToolTip(QApplication::translate("MainWindow", "Cliquez sur une touche activer l'\303\251diteur de touche.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupKeyEditor->setTitle(QApplication::translate("MainWindow", "Edition de touche", 0, QApplication::UnicodeUTF8));
        pushButtonKeyEditorOff->setText(QApplication::translate("MainWindow", "Retour Macro", 0, QApplication::UnicodeUTF8));
        pushButtonEraseKey->setText(QApplication::translate("MainWindow", "Effacer la touche", 0, QApplication::UnicodeUTF8));
        mouseEmulTool->setTitle(QApplication::translate("MainWindow", "Emulation souris", 0, QApplication::UnicodeUTF8));
        pushButtonMouse1->setText(QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8));
        pushButtonMouse3->setText(QApplication::translate("MainWindow", "M", 0, QApplication::UnicodeUTF8));
        pushButtonMouse2->setText(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        pushButtonMouse4->setText(QApplication::translate("MainWindow", "M4", 0, QApplication::UnicodeUTF8));
        pushButtonMouse5->setText(QApplication::translate("MainWindow", "M5", 0, QApplication::UnicodeUTF8));
        macroRepeat->setText(QApplication::translate("MainWindow", "Activ\303\251 la r\303\251p\303\251tition", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "D\303\251lai automatique", 0, QApplication::UnicodeUTF8));
        pushButtonEraseMacro->setText(QApplication::translate("MainWindow", "Tout \303\251ffacer", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
