/********************************************************************************
** Form generated from reading UI file 'programmeprincipalqt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMEPRINCIPALQT_H
#define UI_PROGRAMMEPRINCIPALQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgrammePrincipalQtClass
{
public:
    QAction *actionQuitter;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *inscriptionCandidat;
    QPushButton *inscriptionElecteur;
    QPushButton *desincriptionPersonne;
    QPushButton *quitter;
    QLabel *titrePrincipal;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProgrammePrincipalQtClass)
    {
        if (ProgrammePrincipalQtClass->objectName().isEmpty())
            ProgrammePrincipalQtClass->setObjectName(QString::fromUtf8("ProgrammePrincipalQtClass"));
        ProgrammePrincipalQtClass->resize(800, 600);
        actionQuitter = new QAction(ProgrammePrincipalQtClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(ProgrammePrincipalQtClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(510, 210, 217, 128));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        inscriptionCandidat = new QPushButton(verticalLayoutWidget);
        inscriptionCandidat->setObjectName(QString::fromUtf8("inscriptionCandidat"));

        verticalLayout->addWidget(inscriptionCandidat);

        inscriptionElecteur = new QPushButton(verticalLayoutWidget);
        inscriptionElecteur->setObjectName(QString::fromUtf8("inscriptionElecteur"));

        verticalLayout->addWidget(inscriptionElecteur);

        desincriptionPersonne = new QPushButton(verticalLayoutWidget);
        desincriptionPersonne->setObjectName(QString::fromUtf8("desincriptionPersonne"));

        verticalLayout->addWidget(desincriptionPersonne);

        quitter = new QPushButton(verticalLayoutWidget);
        quitter->setObjectName(QString::fromUtf8("quitter"));

        verticalLayout->addWidget(quitter);

        titrePrincipal = new QLabel(centralwidget);
        titrePrincipal->setObjectName(QString::fromUtf8("titrePrincipal"));
        titrePrincipal->setGeometry(QRect(100, 60, 621, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Sans L"));
        font.setPointSize(18);
        titrePrincipal->setFont(font);
        titrePrincipal->setTextFormat(Qt::PlainText);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(90, 150, 351, 291));
        tableWidget->setColumnCount(3);
        ProgrammePrincipalQtClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProgrammePrincipalQtClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        ProgrammePrincipalQtClass->setMenuBar(menubar);
        statusbar = new QStatusBar(ProgrammePrincipalQtClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProgrammePrincipalQtClass->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionQuitter);

        retranslateUi(ProgrammePrincipalQtClass);
        QObject::connect(quitter, SIGNAL(clicked()), ProgrammePrincipalQtClass, SLOT(close()));
        QObject::connect(actionQuitter, SIGNAL(triggered()), ProgrammePrincipalQtClass, SLOT(close()));
        QObject::connect(inscriptionCandidat, SIGNAL(clicked()), ProgrammePrincipalQtClass, SLOT(dialogCandidat()));
        QObject::connect(inscriptionElecteur, SIGNAL(clicked()), ProgrammePrincipalQtClass, SLOT(dialogElecteur()));
        QObject::connect(desincriptionPersonne, SIGNAL(clicked()), ProgrammePrincipalQtClass, SLOT(dialogSupprimerPersonne()));

        QMetaObject::connectSlotsByName(ProgrammePrincipalQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProgrammePrincipalQtClass)
    {
        ProgrammePrincipalQtClass->setWindowTitle(QApplication::translate("ProgrammePrincipalQtClass", "Fen\303\252tre principale du programme de gestion des \303\251lections", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("ProgrammePrincipalQtClass", "Quitter", 0, QApplication::UnicodeUTF8));
        inscriptionCandidat->setText(QApplication::translate("ProgrammePrincipalQtClass", "Inscription d'un candidat", 0, QApplication::UnicodeUTF8));
        inscriptionElecteur->setText(QApplication::translate("ProgrammePrincipalQtClass", "Inscription d'un \303\251lecteur", 0, QApplication::UnicodeUTF8));
        desincriptionPersonne->setText(QApplication::translate("ProgrammePrincipalQtClass", "D\303\251sinscription d'une personne", 0, QApplication::UnicodeUTF8));
        quitter->setText(QApplication::translate("ProgrammePrincipalQtClass", "Quitter (pour terminer l'application)", 0, QApplication::UnicodeUTF8));
        titrePrincipal->setText(QApplication::translate("ProgrammePrincipalQtClass", "Bienvenue sur le programme de gestion des \303\251lections", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ProgrammePrincipalQtClass", "Nom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ProgrammePrincipalQtClass", "Pr\303\251nom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ProgrammePrincipalQtClass", "Date de Naissance", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("ProgrammePrincipalQtClass", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProgrammePrincipalQtClass: public Ui_ProgrammePrincipalQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMEPRINCIPALQT_H
