#include "candidatinterface.h"
#include "qmessagebox.h"
#include "Candidat.h"
#include <string>


CandidatInterface::CandidatInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.dateEdit->setDate(QDate::currentDate());
	QObject::connect(ui.Bouton_ValiderCandidat, SIGNAL(clicked()), this, SLOT(validerCandidat()));

}

CandidatInterface::~CandidatInterface()
{

}



QString CandidatInterface::reqNas() const{
	return ui.lineEdit_nas->text();
}
QString CandidatInterface::reqNom() const{
	return ui.lineEdit_nom->text();
}
QString CandidatInterface::reqPrenom() const{
	return ui.lineEdit_prenom->text();
}

util::Date CandidatInterface::reqDateNaissance() const{
	return m_dateNaissance;
}

QString CandidatInterface::reqNumRue() const{
	return ui.lineEdit_numero_rue->text();
}
QString CandidatInterface::reqNomRue() const{
	return ui.lineEdit_nom_rue->text();
}
QString CandidatInterface::reqNomVille() const{
	return ui.lineEdit_nom_ville->text();
}
QString CandidatInterface::reqCodePostal() const{
	return ui.lineEdit_code_postal->text();
}
QString CandidatInterface::reqProvince() const{
	return ui.lineEdit_province->text();
}
int CandidatInterface::reqPartiPolitique() const{
	return ui.spinBox_partis_politiques->value();
}

void CandidatInterface::validerCandidat()
{
	if(ui.lineEdit_nas->text().isEmpty()){
		QString message("Le nas ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
	}
	std::string nas = ui.lineEdit_nas->text().toStdString();
	if(!util::validerNas(nas)){
		QString message("Le nas n'est pas valide");
		QMessageBox::information(this, "Erreur", message);
		return;
	}

	if(ui.lineEdit_nom->text().isEmpty()){
		QString message("Le nom ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}
	if(ui.lineEdit_prenom->text().isEmpty()){
		QString message("Le prénom ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}
	QDate dateCourante = QDate::currentDate();
	if(ui.dateEdit->date() == dateCourante){
		QString message("La date de naissance n'est pas valide");
		QMessageBox::information(this, "Erreur", message);
		return;
	} else{
		m_dateNaissance.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(), ui.dateEdit->date().year());
	}


	if(ui.lineEdit_numero_rue->text().isEmpty()){
		QString message("Le numero de rue ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}
	if(ui.lineEdit_nom_rue->text().isEmpty()){
		QString message("Le nom de rue ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}
	if(ui.lineEdit_nom_ville->text().isEmpty()){
		QString message("Le nom de la ville ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}
	if(ui.lineEdit_code_postal->text().isEmpty()){
		QString message("Le code postal ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}
	if(ui.lineEdit_province->text().isEmpty()){
		QString message("La province ne peut être vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}
	/*if(ui.spinBox_partis_politiques->value() < 1 || ui.spinBox_partis_politiques->value() > 5 {
		QString message("Le parti politique ne peut etre vide");
		QMessageBox::information(this, "Erreur", message);
		return;
		}*/
	else {

		accept();

	}
}
