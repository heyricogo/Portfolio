/********************************************************************************
** Form generated from reading UI file 'candidatinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDIDATINTERFACE_H
#define UI_CANDIDATINTERFACE_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CandidatInterfaceClass
{
public:
    QLabel *label_prenom;
    QLabel *label_nom_ville;
    QLabel *label_num_rue;
    QLabel *label_code_postal;
    QLabel *label_province;
    QLabel *label_nom_rue;
    QLabel *label_nom;
    QLabel *label_nas;
    QLabel *label_parti;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_nas;
    QLineEdit *lineEdit_nom_rue;
    QLineEdit *lineEdit_numero_rue;
    QLineEdit *lineEdit_nom_ville;
    QLineEdit *lineEdit_code_postal;
    QLineEdit *lineEdit_province;
    QPushButton *Bouton_ValiderCandidat;
    QLabel *TitrePageCandidat;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *liste_partis_politiques;
    QLabel *liste_partis_politiques_2;
    QLabel *liste_partis_politiques_3;
    QLabel *liste_partis_politiques_4;
    QLabel *liste_partis_politiques_5;
    QLabel *label_date_naissance;
    QDateEdit *dateEdit;
    QSpinBox *spinBox_partis_politiques;

    void setupUi(QDialog *CandidatInterfaceClass)
    {
        if (CandidatInterfaceClass->objectName().isEmpty())
            CandidatInterfaceClass->setObjectName(QString::fromUtf8("CandidatInterfaceClass"));
        CandidatInterfaceClass->resize(633, 403);
        label_prenom = new QLabel(CandidatInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(30, 110, 55, 17));
        label_nom_ville = new QLabel(CandidatInterfaceClass);
        label_nom_ville->setObjectName(QString::fromUtf8("label_nom_ville"));
        label_nom_ville->setGeometry(QRect(340, 110, 91, 16));
        label_num_rue = new QLabel(CandidatInterfaceClass);
        label_num_rue->setObjectName(QString::fromUtf8("label_num_rue"));
        label_num_rue->setGeometry(QRect(340, 50, 101, 16));
        label_code_postal = new QLabel(CandidatInterfaceClass);
        label_code_postal->setObjectName(QString::fromUtf8("label_code_postal"));
        label_code_postal->setGeometry(QRect(340, 140, 91, 16));
        label_province = new QLabel(CandidatInterfaceClass);
        label_province->setObjectName(QString::fromUtf8("label_province"));
        label_province->setGeometry(QRect(340, 170, 91, 16));
        label_nom_rue = new QLabel(CandidatInterfaceClass);
        label_nom_rue->setObjectName(QString::fromUtf8("label_nom_rue"));
        label_nom_rue->setGeometry(QRect(340, 80, 91, 16));
        label_nom = new QLabel(CandidatInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(30, 80, 55, 17));
        label_nas = new QLabel(CandidatInterfaceClass);
        label_nas->setObjectName(QString::fromUtf8("label_nas"));
        label_nas->setGeometry(QRect(30, 50, 55, 17));
        label_parti = new QLabel(CandidatInterfaceClass);
        label_parti->setObjectName(QString::fromUtf8("label_parti"));
        label_parti->setGeometry(QRect(340, 210, 141, 16));
        lineEdit_nom = new QLineEdit(CandidatInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(190, 70, 113, 27));
        lineEdit_prenom = new QLineEdit(CandidatInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(190, 100, 113, 27));
        lineEdit_nas = new QLineEdit(CandidatInterfaceClass);
        lineEdit_nas->setObjectName(QString::fromUtf8("lineEdit_nas"));
        lineEdit_nas->setGeometry(QRect(190, 40, 113, 27));
        lineEdit_nom_rue = new QLineEdit(CandidatInterfaceClass);
        lineEdit_nom_rue->setObjectName(QString::fromUtf8("lineEdit_nom_rue"));
        lineEdit_nom_rue->setGeometry(QRect(500, 70, 113, 27));
        lineEdit_numero_rue = new QLineEdit(CandidatInterfaceClass);
        lineEdit_numero_rue->setObjectName(QString::fromUtf8("lineEdit_numero_rue"));
        lineEdit_numero_rue->setGeometry(QRect(500, 40, 113, 27));
        lineEdit_nom_ville = new QLineEdit(CandidatInterfaceClass);
        lineEdit_nom_ville->setObjectName(QString::fromUtf8("lineEdit_nom_ville"));
        lineEdit_nom_ville->setGeometry(QRect(500, 100, 113, 27));
        lineEdit_code_postal = new QLineEdit(CandidatInterfaceClass);
        lineEdit_code_postal->setObjectName(QString::fromUtf8("lineEdit_code_postal"));
        lineEdit_code_postal->setGeometry(QRect(500, 130, 113, 27));
        lineEdit_province = new QLineEdit(CandidatInterfaceClass);
        lineEdit_province->setObjectName(QString::fromUtf8("lineEdit_province"));
        lineEdit_province->setGeometry(QRect(500, 160, 113, 27));
        Bouton_ValiderCandidat = new QPushButton(CandidatInterfaceClass);
        Bouton_ValiderCandidat->setObjectName(QString::fromUtf8("Bouton_ValiderCandidat"));
        Bouton_ValiderCandidat->setGeometry(QRect(230, 360, 191, 27));
        TitrePageCandidat = new QLabel(CandidatInterfaceClass);
        TitrePageCandidat->setObjectName(QString::fromUtf8("TitrePageCandidat"));
        TitrePageCandidat->setGeometry(QRect(220, 10, 221, 17));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        TitrePageCandidat->setFont(font);
        verticalLayoutWidget = new QWidget(CandidatInterfaceClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(340, 230, 185, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        liste_partis_politiques = new QLabel(verticalLayoutWidget);
        liste_partis_politiques->setObjectName(QString::fromUtf8("liste_partis_politiques"));

        verticalLayout->addWidget(liste_partis_politiques);

        liste_partis_politiques_2 = new QLabel(verticalLayoutWidget);
        liste_partis_politiques_2->setObjectName(QString::fromUtf8("liste_partis_politiques_2"));

        verticalLayout->addWidget(liste_partis_politiques_2);

        liste_partis_politiques_3 = new QLabel(verticalLayoutWidget);
        liste_partis_politiques_3->setObjectName(QString::fromUtf8("liste_partis_politiques_3"));

        verticalLayout->addWidget(liste_partis_politiques_3);

        liste_partis_politiques_4 = new QLabel(verticalLayoutWidget);
        liste_partis_politiques_4->setObjectName(QString::fromUtf8("liste_partis_politiques_4"));

        verticalLayout->addWidget(liste_partis_politiques_4);

        liste_partis_politiques_5 = new QLabel(verticalLayoutWidget);
        liste_partis_politiques_5->setObjectName(QString::fromUtf8("liste_partis_politiques_5"));
        liste_partis_politiques_5->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(liste_partis_politiques_5);

        label_date_naissance = new QLabel(CandidatInterfaceClass);
        label_date_naissance->setObjectName(QString::fromUtf8("label_date_naissance"));
        label_date_naissance->setGeometry(QRect(30, 170, 111, 17));
        dateEdit = new QDateEdit(CandidatInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(190, 160, 110, 27));
        dateEdit->setDateTime(QDateTime(QDate(1997, 1, 1), QTime(23, 59, 59)));
        dateEdit->setMaximumDate(QDate(2037, 12, 31));
        dateEdit->setMinimumDate(QDate(1970, 1, 1));
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(1997, 1, 1));
        spinBox_partis_politiques = new QSpinBox(CandidatInterfaceClass);
        spinBox_partis_politiques->setObjectName(QString::fromUtf8("spinBox_partis_politiques"));
        spinBox_partis_politiques->setGeometry(QRect(500, 200, 49, 27));
        spinBox_partis_politiques->setMinimum(1);
        spinBox_partis_politiques->setMaximum(5);
        spinBox_partis_politiques->setValue(1);

        retranslateUi(CandidatInterfaceClass);
        QObject::connect(Bouton_ValiderCandidat, SIGNAL(clicked()), CandidatInterfaceClass, SLOT(validerCandidat()));

        QMetaObject::connectSlotsByName(CandidatInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *CandidatInterfaceClass)
    {
        CandidatInterfaceClass->setWindowTitle(QApplication::translate("CandidatInterfaceClass", "CandidatInterface", 0, QApplication::UnicodeUTF8));
        label_prenom->setText(QApplication::translate("CandidatInterfaceClass", "Pr\303\251nom", 0, QApplication::UnicodeUTF8));
        label_nom_ville->setText(QApplication::translate("CandidatInterfaceClass", "Nom de la ville", 0, QApplication::UnicodeUTF8));
        label_num_rue->setText(QApplication::translate("CandidatInterfaceClass", "Num\303\251ro de la rue", 0, QApplication::UnicodeUTF8));
        label_code_postal->setText(QApplication::translate("CandidatInterfaceClass", "Code postal", 0, QApplication::UnicodeUTF8));
        label_province->setText(QApplication::translate("CandidatInterfaceClass", "Province", 0, QApplication::UnicodeUTF8));
        label_nom_rue->setText(QApplication::translate("CandidatInterfaceClass", "Nom de la rue", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("CandidatInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        label_nas->setText(QApplication::translate("CandidatInterfaceClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_parti->setText(QApplication::translate("CandidatInterfaceClass", "Parti politique ", 0, QApplication::UnicodeUTF8));
        Bouton_ValiderCandidat->setText(QApplication::translate("CandidatInterfaceClass", "Valider le nouveau candidat", 0, QApplication::UnicodeUTF8));
        TitrePageCandidat->setText(QApplication::translate("CandidatInterfaceClass", "Ajout d'un Candidat", 0, QApplication::UnicodeUTF8));
        liste_partis_politiques->setText(QApplication::translate("CandidatInterfaceClass", "1. BLOC_QUEBECOIS", 0, QApplication::UnicodeUTF8));
        liste_partis_politiques_2->setText(QApplication::translate("CandidatInterfaceClass", "2. CONSERVATEURS", 0, QApplication::UnicodeUTF8));
        liste_partis_politiques_3->setText(QApplication::translate("CandidatInterfaceClass", "3. INDEPENDANT", 0, QApplication::UnicodeUTF8));
        liste_partis_politiques_4->setText(QApplication::translate("CandidatInterfaceClass", "4. LIBERAL", 0, QApplication::UnicodeUTF8));
        liste_partis_politiques_5->setText(QApplication::translate("CandidatInterfaceClass", "5. NOUVEAU PARTI DEMOCRATE", 0, QApplication::UnicodeUTF8));
        label_date_naissance->setText(QApplication::translate("CandidatInterfaceClass", "Date de naissance", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CandidatInterfaceClass: public Ui_CandidatInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDIDATINTERFACE_H
