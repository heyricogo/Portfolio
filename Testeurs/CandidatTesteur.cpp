/*
* \file CandidatTesteur.cpp
* \brief  Fichier de tests unitaires pour la classe Candidat
* \author Eric Cogoluenhes
*/

#include <gtest/gtest.h>
#include "Candidat.h"
#include "Personne.h"
#include "Date.h"
#include "Adresse.h"

using namespace elections;

/**
 * \brief Test du Constructeur Candidat::Candidat()
 * cas valide :
 * 	ConstructeurParametresValides: Création d'un Candidat valide
 * cas invalide :
 * 	ConstructeurPartiInvalide : Parti invalide
 */

TEST(CandidatConstructeur,ConstructeurParametreValides)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	ASSERT_EQ("046 454 286",unCandidat.reqNas());
	ASSERT_EQ("inconnu",unCandidat.reqNom());
	ASSERT_EQ("inconnu",unCandidat.reqPrenom());
	ASSERT_EQ(uneDate,unCandidat.reqDateNaissance());
	ASSERT_EQ("LIBERAL", unCandidat.reqPartiPolitiqueString());
}

TEST(CandidatConstructeur,ConstructeurPartiInValides)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse,50);

	ASSERT_EQ("PS",unCandidat.reqPartiPolitiqueString());
}

/**
 * \class CandidatValide
 * \brief Fixture pour les tests sur un Candidat
 */

class CandidatValide: public ::testing::Test // Un Candidat : "046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 0
{
public:
	util::Date uneDate;
	util::Adresse uneAdresse;
	CandidatValide() :
		f_CandidatTest("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse,0)
	{

	};

	Candidat f_CandidatTest;
};


/**
 * \brief Test de la méthode const std::string& Candidat::reqPartiPolitiqueString() const
 *        cas valide reqParti: Création Candidat et de son parti valide et test du parti
 *        cas invalide Aucun d'identifié
 */
TEST_F(CandidatValide, reqPartiPolitiqueString)
{
	ASSERT_EQ("BLOC_QUEBECOIS", f_CandidatTest.reqPartiPolitiqueString());

}

