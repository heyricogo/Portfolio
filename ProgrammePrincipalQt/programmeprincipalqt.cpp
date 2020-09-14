#include "programmeprincipalqt.h"
#include "Date.h"
#include "Adresse.h"
#include "electeurinterface.h"
#include "candidatinterface.h"
#include "PersonneException.h"
#include <QMessageBox>
#include "Circonscription.h"
#include "desinscriptionpersonne.h"

ProgrammePrincipalQt::ProgrammePrincipalQt(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setColumnWidth(0, 100);
	ui.tableWidget->setColumnWidth(1, 100);
	ui.tableWidget->setColumnWidth(2, 150);
	QObject::connect(ui.inscriptionCandidat, SIGNAL(clicked()), this, SLOT(dialogCandidat()));
	QObject::connect(ui.inscriptionElecteur, SIGNAL(clicked()), this, SLOT(dialogElecteur()));
	QObject::connect(ui.desincriptionPersonne, SIGNAL(clicked()), this, SLOT(dialogSupprimerPersonne()));
	QObject::connect(ui.quitter, SIGNAL(clicked()), this, SLOT(close()));
	util::Date uneDate;
	util::Adresse uneAdresse;
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	Circonscription uneCirconscription("1", unCandidat);
}

ProgrammePrincipalQt::~ProgrammePrincipalQt()
{

}

void ProgrammePrincipalQt::dialogCandidat(){
	CandidatInterface saisieCandidat(this);
	if(saisieCandidat.exec()){
		util::Adresse adresseCandidat(saisieCandidat.reqNumRue().toInt(),
					saisieCandidat.reqNomRue().toStdString(),
					saisieCandidat.reqNomVille().toStdString(),
					saisieCandidat.reqCodePostal().toStdString(),
					saisieCandidat.reqProvince().toStdString());
		std::string candidatNas = saisieCandidat.reqNas().toStdString();
		std::string candidatPrenom = saisieCandidat.reqPrenom().toStdString();
		std::string candidatNom = saisieCandidat.reqNom().toStdString();
		util::Date dateNaissance = saisieCandidat.reqDateNaissance();
		int candidatPartiPolitique = saisieCandidat.reqPartiPolitique();
		ajouterCandidat(candidatNas, candidatPrenom, candidatNom, dateNaissance,
				adresseCandidat, candidatPartiPolitique);
		int nombreDeLigne = ui.tableWidget->rowCount();
		QString date = QString::fromStdString(saisieCandidat.reqDateNaissance().reqDateFormatee());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem(saisieCandidat.reqNom()));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem(saisieCandidat.reqPrenom()));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
	}
}

void ProgrammePrincipalQt::ajouterCandidat(const std::string& p_nas, const std::string& p_prenom,
			const std::string& p_nom, const util::Date&	p_dateNaissance,
			const util::Adresse& p_adresse, int	p_parti){

	try{
		Candidat nouveau_candidat(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse, p_parti);
		Circonscription uneCirconscription("1", nouveau_candidat);
		//int tailleAvant = m_vInscrits.size();
		uneCirconscription.inscrire(nouveau_candidat);
		//int tailleApres = m_vInscrits.size();

		if(*m_vInscrits.back() == nouveau_candidat)
			throw PersonneDejaPresenteException("Impossible d'ajouter ce candidat, il est déjà présent dans la liste");
		//m_vInscrits.push_back(new Candidat(nouveau_candidat));
	} catch (PersonneDejaPresenteException& e){
		QString message = (e.what());
		QMessageBox::information(this, "Erreur", message);
	}
	};

void ProgrammePrincipalQt::dialogElecteur(){
	ElecteurInterface saisieElecteur(this);
	if(saisieElecteur.exec()){
		util::Adresse adresseElecteur(saisieElecteur.reqNumRue().toInt(),
					saisieElecteur.reqNomRue().toStdString(),
					saisieElecteur.reqNomVille().toStdString(),
					saisieElecteur.reqCodePostal().toStdString(),
					saisieElecteur.reqProvince().toStdString());
		std::string candidatNas = saisieElecteur.reqNas().toStdString();
		std::string candidatPrenom = saisieElecteur.reqPrenom().toStdString();
		std::string candidatNom = saisieElecteur.reqNom().toStdString();
		util::Date dateNaissance = saisieElecteur.reqDateNaissance();
		ajouterElecteur(candidatNas, candidatPrenom, candidatNom, dateNaissance,
				adresseElecteur);
		int nombreDeLigne = ui.tableWidget->rowCount();
		QString date = QString::fromStdString(saisieElecteur.reqDateNaissance().reqDateFormatee());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem(saisieElecteur.reqNom()));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem(saisieElecteur.reqPrenom()));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
	}
}

void ProgrammePrincipalQt::ajouterElecteur(const std::string& p_nas, const std::string& p_prenom,
			const std::string& p_nom, const util::Date&	p_dateNaissance,
			const util::Adresse& p_adresse){

	try{
		int p_parti = 1;
		Candidat nouveau_candidat(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse, p_parti);
		Circonscription uneCirconscription("1", nouveau_candidat);
		Electeur nouvel_electeur(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse);
		//int tailleAvant = m_vInscrits.size();
		uneCirconscription.inscrire(nouvel_electeur);
		//int tailleApres = m_vInscrits.size();

		if(*m_vInscrits.back() == nouvel_electeur)
			throw PersonneDejaPresenteException("Impossible d'ajouter cet électeur, il est déjà présent dans la liste");
		//m_vInscrits.push_back(new Candidat(nouveau_candidat));
	} catch (PersonneDejaPresenteException& e){
		QString message = (e.what());
		QMessageBox::information(this, "Erreur", message);
	}
	};

void ProgrammePrincipalQt::dialogSupprimerPersonne(){
	DesinscriptionPersonne suppressionPersonne(this);
	if (suppressionPersonne.exec()){
		if (suppressionPersonne.reqNom().isEmpty())
		{
			supprimerPersonne("", suppressionPersonne.reqPrenom().toStdString());
			int nombreDeLigne = ui.tableWidget->rowCount();
			ui.tableWidget->setRowCount(nombreDeLigne + 1);
		}
		else if (suppressionPersonne.reqPrenom().isEmpty())
			supprimerPersonne(suppressionPersonne.reqNom().toStdString(), "");
		else
			supprimerPersonne(suppressionPersonne.reqNom().toStdString(), suppressionPersonne.reqPrenom().toStdString());
	}
}


void ProgrammePrincipalQt::supprimerPersonne(const std::string& p_nom, const std::string& p_prenom){
	try {
		std::vector<Personne*>::iterator it;
		int tailleAvant = m_vInscrits.size();
		for(it = m_vInscrits.begin(); it < m_vInscrits.end(); it++){
			if((*it)->reqNom() == p_nom && (*it)->reqPrenom() == p_prenom){
				delete (*it);
				it = m_vInscrits.erase(it);
			}
		}
		int tailleApres = m_vInscrits.size();
		if(tailleAvant == tailleApres)
			throw PersonneAbsenteException("Impossible de supprimer une personne qui n'existe pas dans la "
									"liste");
	} catch(PersonneAbsenteException& e)
	{
		QString message = (e.what());
		QMessageBox::information(this, "Erreur", message);
	}
}
