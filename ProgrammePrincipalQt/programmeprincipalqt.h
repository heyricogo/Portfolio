#ifndef PROGRAMMEPRINCIPALQT_H
#define PROGRAMMEPRINCIPALQT_H

#include <QtGui/QMainWindow>
#include "ui_programmeprincipalqt.h"
#include "Candidat.h"
#include "Electeur.h"
#include <string>
#include <vector>

using namespace elections;

class ProgrammePrincipalQt : public QMainWindow
{
    Q_OBJECT

public:
    ProgrammePrincipalQt(QWidget *parent = 0);
    ~ProgrammePrincipalQt();
    void ajouterCandidat(const std::string& p_nas, const std::string& p_prenom,
			const std::string& p_nom, const util::Date&	p_dateNaissance,
			const util::Adresse& p_adresse, int	p_parti);
    void ajouterElecteur(const std::string& p_nas, const std::string& p_prenom,
			const std::string& p_nom, const util::Date&	p_dateNaissance,
			const util::Adresse& p_adresse);
    void supprimerPersonne(const std::string& p_nom, const std::string& p_prenom);


private slots:
	void dialogCandidat();
	void dialogElecteur();
	void dialogSupprimerPersonne();

private:
    Ui::ProgrammePrincipalQtClass ui;
    std::vector<Personne *> m_vInscrits;
};

#endif // PROGRAMMEPRINCIPALQT_H
