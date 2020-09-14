/*
* \file ElecteurTesteur.cpp
* \brief  Fichier de tests unitaires pour la classe Electeur
* \author Eric Cogoluenhes
*/

#include <gtest/gtest.h>
#include "Electeur.h"
#include "Date.h"
#include "Adresse.h"

using namespace elections;

/**
 * \brief Test du Constructeur Electeur::Electeur()
 * cas valide :
 * 	ConstructeurParametresValides: Création d'un Electeur valide
 * cas invalide :
 * 	Aucun non testé pour la Classe Personne
 */

TEST(ElecteurConstructeur,ConstructeurParametreValides)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Electeur unElecteur("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse);

	ASSERT_EQ("046 454 286",unElecteur.reqNas());
	ASSERT_EQ("inconnu",unElecteur.reqNom());
	ASSERT_EQ("inconnu",unElecteur.reqPrenom());
	ASSERT_EQ(uneDate,unElecteur.reqDateNaissance());
}

