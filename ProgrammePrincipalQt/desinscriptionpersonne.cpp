#include "desinscriptionpersonne.h"
#include <QMessageBox>

DesinscriptionPersonne::DesinscriptionPersonne(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_valider_suppression, SIGNAL(clicked()), this, SLOT(valideSuppression()));
}

DesinscriptionPersonne::~DesinscriptionPersonne()
{

}

QString DesinscriptionPersonne::reqNom() const{
	return ui.lineEdit_nom->text();
}

QString DesinscriptionPersonne::reqPrenom() const{
   	return ui.lineEdit_prenom->text();
}

void DesinscriptionPersonne::valideSuppression(){
	if (ui.lineEdit_nom->text().isEmpty() && ui.lineEdit_prenom->text().isEmpty()){
		QString message("Veuillez saisir soit le nom ou le prenom ou encore les deux");
		QMessageBox::information(this, "ERREUR", message);
		return;
	} else {
		accept();
	}
}

