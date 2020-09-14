/********************************************************************************
** Form generated from reading UI file 'desinscriptionpersonne.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESINSCRIPTIONPERSONNE_H
#define UI_DESINSCRIPTIONPERSONNE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DesinscriptionPersonneClass
{
public:
    QLineEdit *lineEdit_nom;
    QLabel *TitrePageDesinscription;
    QPushButton *pushButton_valider_suppression;
    QLabel *label_prenom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_nom;

    void setupUi(QDialog *DesinscriptionPersonneClass)
    {
        if (DesinscriptionPersonneClass->objectName().isEmpty())
            DesinscriptionPersonneClass->setObjectName(QString::fromUtf8("DesinscriptionPersonneClass"));
        DesinscriptionPersonneClass->resize(400, 300);
        lineEdit_nom = new QLineEdit(DesinscriptionPersonneClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(150, 100, 221, 31));
        TitrePageDesinscription = new QLabel(DesinscriptionPersonneClass);
        TitrePageDesinscription->setObjectName(QString::fromUtf8("TitrePageDesinscription"));
        TitrePageDesinscription->setGeometry(QRect(20, 20, 371, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        TitrePageDesinscription->setFont(font);
        TitrePageDesinscription->setAlignment(Qt::AlignCenter);
        pushButton_valider_suppression = new QPushButton(DesinscriptionPersonneClass);
        pushButton_valider_suppression->setObjectName(QString::fromUtf8("pushButton_valider_suppression"));
        pushButton_valider_suppression->setGeometry(QRect(120, 240, 151, 27));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_valider_suppression->setFont(font1);
        label_prenom = new QLabel(DesinscriptionPersonneClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(20, 150, 111, 31));
        lineEdit_prenom = new QLineEdit(DesinscriptionPersonneClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(150, 150, 221, 31));
        label_nom = new QLabel(DesinscriptionPersonneClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(20, 100, 111, 31));

        retranslateUi(DesinscriptionPersonneClass);
        QObject::connect(pushButton_valider_suppression, SIGNAL(clicked()), DesinscriptionPersonneClass, SLOT(valideSuppression()));

        QMetaObject::connectSlotsByName(DesinscriptionPersonneClass);
    } // setupUi

    void retranslateUi(QDialog *DesinscriptionPersonneClass)
    {
        DesinscriptionPersonneClass->setWindowTitle(QApplication::translate("DesinscriptionPersonneClass", "DesinscriptionPersonne", 0, QApplication::UnicodeUTF8));
        TitrePageDesinscription->setText(QApplication::translate("DesinscriptionPersonneClass", "Desinscription d'une personne de la liste", 0, QApplication::UnicodeUTF8));
        pushButton_valider_suppression->setText(QApplication::translate("DesinscriptionPersonneClass", "Valider suppression", 0, QApplication::UnicodeUTF8));
        label_prenom->setText(QApplication::translate("DesinscriptionPersonneClass", "Prenom :", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("DesinscriptionPersonneClass", "Nom :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DesinscriptionPersonneClass: public Ui_DesinscriptionPersonneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESINSCRIPTIONPERSONNE_H
