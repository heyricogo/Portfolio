/********************************************************************************
** Form generated from reading UI file 'electeurinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELECTEURINTERFACE_H
#define UI_ELECTEURINTERFACE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ElecteurInterfaceClass
{
public:
    QLabel *label_prenom;
    QLineEdit *lineEdit_nas;
    QLabel *TitrePageElecteur;
    QPushButton *Bouton_ValiderElecteur;
    QLineEdit *lineEdit_province;
    QDateEdit *dateEdit;
    QLabel *label_num_rue;
    QLineEdit *lineEdit_nom_ville;
    QLineEdit *lineEdit_prenom;
    QLabel *label_code_postal;
    QLabel *label_nom_rue;
    QLineEdit *lineEdit_code_postal;
    QLabel *label_date_naissance;
    QLabel *label_province;
    QLabel *label_nom_ville;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_numero_rue;
    QLineEdit *lineEdit_nom_rue;
    QLabel *label_nas;
    QLabel *label_nom;

    void setupUi(QDialog *ElecteurInterfaceClass)
    {
        if (ElecteurInterfaceClass->objectName().isEmpty())
            ElecteurInterfaceClass->setObjectName(QString::fromUtf8("ElecteurInterfaceClass"));
        ElecteurInterfaceClass->resize(627, 269);
        label_prenom = new QLabel(ElecteurInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(10, 120, 55, 17));
        lineEdit_nas = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_nas->setObjectName(QString::fromUtf8("lineEdit_nas"));
        lineEdit_nas->setGeometry(QRect(170, 50, 113, 27));
        TitrePageElecteur = new QLabel(ElecteurInterfaceClass);
        TitrePageElecteur->setObjectName(QString::fromUtf8("TitrePageElecteur"));
        TitrePageElecteur->setGeometry(QRect(200, 20, 221, 17));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        TitrePageElecteur->setFont(font);
        Bouton_ValiderElecteur = new QPushButton(ElecteurInterfaceClass);
        Bouton_ValiderElecteur->setObjectName(QString::fromUtf8("Bouton_ValiderElecteur"));
        Bouton_ValiderElecteur->setGeometry(QRect(220, 220, 191, 27));
        lineEdit_province = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_province->setObjectName(QString::fromUtf8("lineEdit_province"));
        lineEdit_province->setGeometry(QRect(480, 170, 113, 27));
        dateEdit = new QDateEdit(ElecteurInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(170, 170, 110, 27));
        dateEdit->setMaximumDate(QDate(2037, 12, 31));
        dateEdit->setMinimumDate(QDate(1970, 1, 1));
        dateEdit->setCalendarPopup(true);
        label_num_rue = new QLabel(ElecteurInterfaceClass);
        label_num_rue->setObjectName(QString::fromUtf8("label_num_rue"));
        label_num_rue->setGeometry(QRect(320, 60, 101, 16));
        lineEdit_nom_ville = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_nom_ville->setObjectName(QString::fromUtf8("lineEdit_nom_ville"));
        lineEdit_nom_ville->setGeometry(QRect(480, 110, 113, 27));
        lineEdit_prenom = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(170, 110, 113, 27));
        label_code_postal = new QLabel(ElecteurInterfaceClass);
        label_code_postal->setObjectName(QString::fromUtf8("label_code_postal"));
        label_code_postal->setGeometry(QRect(320, 150, 91, 16));
        label_nom_rue = new QLabel(ElecteurInterfaceClass);
        label_nom_rue->setObjectName(QString::fromUtf8("label_nom_rue"));
        label_nom_rue->setGeometry(QRect(320, 90, 91, 16));
        lineEdit_code_postal = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_code_postal->setObjectName(QString::fromUtf8("lineEdit_code_postal"));
        lineEdit_code_postal->setGeometry(QRect(480, 140, 113, 27));
        label_date_naissance = new QLabel(ElecteurInterfaceClass);
        label_date_naissance->setObjectName(QString::fromUtf8("label_date_naissance"));
        label_date_naissance->setGeometry(QRect(10, 180, 111, 17));
        label_province = new QLabel(ElecteurInterfaceClass);
        label_province->setObjectName(QString::fromUtf8("label_province"));
        label_province->setGeometry(QRect(320, 180, 91, 16));
        label_nom_ville = new QLabel(ElecteurInterfaceClass);
        label_nom_ville->setObjectName(QString::fromUtf8("label_nom_ville"));
        label_nom_ville->setGeometry(QRect(320, 120, 91, 16));
        lineEdit_nom = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(170, 80, 113, 27));
        lineEdit_numero_rue = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_numero_rue->setObjectName(QString::fromUtf8("lineEdit_numero_rue"));
        lineEdit_numero_rue->setGeometry(QRect(480, 50, 113, 27));
        lineEdit_nom_rue = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_nom_rue->setObjectName(QString::fromUtf8("lineEdit_nom_rue"));
        lineEdit_nom_rue->setGeometry(QRect(480, 80, 113, 27));
        label_nas = new QLabel(ElecteurInterfaceClass);
        label_nas->setObjectName(QString::fromUtf8("label_nas"));
        label_nas->setGeometry(QRect(10, 60, 55, 17));
        label_nom = new QLabel(ElecteurInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(10, 90, 55, 17));

        retranslateUi(ElecteurInterfaceClass);
        QObject::connect(Bouton_ValiderElecteur, SIGNAL(clicked()), ElecteurInterfaceClass, SLOT(validerElecteur()));

        QMetaObject::connectSlotsByName(ElecteurInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *ElecteurInterfaceClass)
    {
        ElecteurInterfaceClass->setWindowTitle(QApplication::translate("ElecteurInterfaceClass", "ElecteurInterface", 0, QApplication::UnicodeUTF8));
        label_prenom->setText(QApplication::translate("ElecteurInterfaceClass", "Pr\303\251nom", 0, QApplication::UnicodeUTF8));
        TitrePageElecteur->setText(QApplication::translate("ElecteurInterfaceClass", "Ajout d'un Electeur", 0, QApplication::UnicodeUTF8));
        Bouton_ValiderElecteur->setText(QApplication::translate("ElecteurInterfaceClass", "Valider le nouvel \303\251lecteur", 0, QApplication::UnicodeUTF8));
        label_num_rue->setText(QApplication::translate("ElecteurInterfaceClass", "Num\303\251ro de la rue", 0, QApplication::UnicodeUTF8));
        label_code_postal->setText(QApplication::translate("ElecteurInterfaceClass", "Code postal", 0, QApplication::UnicodeUTF8));
        label_nom_rue->setText(QApplication::translate("ElecteurInterfaceClass", "Nom de la rue", 0, QApplication::UnicodeUTF8));
        label_date_naissance->setText(QApplication::translate("ElecteurInterfaceClass", "Date de naissance", 0, QApplication::UnicodeUTF8));
        label_province->setText(QApplication::translate("ElecteurInterfaceClass", "Province", 0, QApplication::UnicodeUTF8));
        label_nom_ville->setText(QApplication::translate("ElecteurInterfaceClass", "Nom de la ville", 0, QApplication::UnicodeUTF8));
        label_nas->setText(QApplication::translate("ElecteurInterfaceClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("ElecteurInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElecteurInterfaceClass: public Ui_ElecteurInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELECTEURINTERFACE_H
