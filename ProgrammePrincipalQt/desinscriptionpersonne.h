#ifndef DESINSCRIPTIONPERSONNE_H
#define DESINSCRIPTIONPERSONNE_H

#include <QtGui/QDialog>
#include "ui_desinscriptionpersonne.h"

class DesinscriptionPersonne : public QDialog
{
    Q_OBJECT

public:
    DesinscriptionPersonne(QWidget *parent = 0);
    ~DesinscriptionPersonne();
    QString reqNom() const;
    QString reqPrenom() const;

private slots:
	void valideSuppression();

private:
    Ui::DesinscriptionPersonneClass ui;
};

#endif // DESINSCRIPTIONPERSONNE_H
