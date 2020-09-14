#ifndef CANDIDATINTERFACE_H
#define CANDIDATINTERFACE_H

#include <QtGui/QDialog>
#include "ui_candidatinterface.h"
#include "Date.h"

class CandidatInterface : public QDialog
{
    Q_OBJECT

public:
    CandidatInterface(QWidget *parent = 0);
    ~CandidatInterface();
    void ajouterCandidat();

    QString reqNas() const;
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDateNaissance() const;

    QString	reqNumRue() const;
    QString reqNomRue() const;
    QString reqNomVille() const;
    QString reqCodePostal() const;
    QString reqProvince() const;
    int reqPartiPolitique() const;

private slots:
	void validerCandidat();

private:
    Ui::CandidatInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // CANDIDATINTERFACE_H
