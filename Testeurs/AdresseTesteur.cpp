/**
 * \file TesteurAdresse.cpp
 * \brief  Fichier de tests unitaires pour la classe Adresse
 * \author Eric Cogoluenhes
 */

#include <gtest/gtest.h>
#include "Adresse.h"
#include "ContratException.h"

using namespace util;
/**
 * \brief Test du Constructeur Adresse::Adresse()
 * cas valide :
 * 	ConstructeurVide :	Adresse sans mentionner numero de rue, nom de rue, ville, ni code postal, ni province
 * 	ConstructeurParametresValides: Création d'une date valide
 * cas invalide :
 * 	ConstructeurNbRueInvalide : numero rue invalide
 * 	ConstructeurNomRueInvalide : nom rue invalide
 * 	ConstructeurNomVilleInvalide : nom ville invalide
 * 	ConstructeurCodePostalInvalide : code postal invalide
 * 	ConstructeurProvinceInvalide : province invalide
 */

TEST(AdresseConstructeur,ConstructeurVide)
{
	Adresse uneAdresse;
	ASSERT_EQ("1, rue inconnue, inconnue, G1V 0A7, QC",uneAdresse.reqAdresse());
}

TEST(AdresseConstructeur,ConstructeurParametreValides)
{
	Adresse uneAdresse(1, "rue inconnue", "inconnue", "G1V 0A7", "QC");
	ASSERT_EQ("1, rue inconnue, inconnue, G1V 0A7, QC",uneAdresse.reqAdresse());
}

TEST(AdresseConstructeur,ConstructeurNbRueInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(0, "rue inconnue","inconnue", "G1V 0A7", "QC"), PreconditionException) << "L'adresse ne prend pas de numero de rue egal a 0";
}


TEST(AdresseConstructeur,ConstructeurNomRueInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "","inconnue", "G1V 0A7", "QC"), PreconditionException) << "L'adresse ne prend pas de nom de rue vide";
}


TEST(AdresseConstructeur,ConstructeurNomVilleInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "rue inconnue","", "G1V 0A7", "QC"), PreconditionException) << "L'adresse ne prend pas de nom de ville vie";
}

TEST(AdresseConstructeur,ConstructeurCodePostalInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "rue inconnue","inconnue", "", "QC"),PreconditionException) << "L'adresse ne prend pas de code postal vide";
}

TEST(AdresseConstructeur,ConstructeurProvinceInvalide)
{
	ASSERT_THROW(Adresse uneAdresse(1, "rue inconnue","inconnue", "G1V 0A7", ""), PreconditionException) << "L'adresse ne prend pas de province vide";
}

/**
 * \class AdresseVide
 * \brief Fixture pour les tests sur une adresse
 */

class AdresseVide: public ::testing::Test // Une adresse : "1, rue inconnue, inconnue, G1V 0A7, QC"
{
public:
	Adresse f_adresseTest;
};

/**
 * \brief Test de la méthode void asgAdresse(const int p_nbRue, const std::string p_nomRue,
			const std::string p_nomVille, const std::string p_province, const std::string p_codePostal);
 *   cas valide
 *     	AjouteAdresseValide:Ajout d'une adresse valide.
 *
 *    cas invalide Aucun d'identifié.
 *    	AjouteNbRueInvalide:Ajout d'un numero de rue invalide.
 *   	AjouteNomRueInvalide:Ajout d'un nom de rue invalide.
 *      AjouteNomVilleInvalide:Ajout d'un nom de ville invalide.
 *   	AjouteCodePostalInvalide:Ajout d'un code postal invalide.
 *   	AjouteProvinceInvalide:Ajout d'une province invalide.
 *
 */
TEST_F(AdresseVide, AjouteAdresseValide)
{
	ASSERT_EQ("12345, rue sans issue, far far lointain, G2R N6C, Oz", f_adresseTest.reqAdresse());

	f_adresseTest.asgAdresse(12345,"rue sans issue","far far lointain","G2R N6C","Oz");
	ASSERT_EQ("12345, rue sans issue, far far lointain, G2R N6C, Oz", f_adresseTest.reqAdresse());

}

TEST_F(AdresseVide, AjouteNbRueInvalide)
{
	f_adresseTest.asgNbRue(12345);
	f_adresseTest.asgNomRue("rue sans issue");
	f_adresseTest.asgNomVille("far far lointain");
	f_adresseTest.asgCodePostal("G2R N6C");
	f_adresseTest.asgProvince("Oz");

	ASSERT_EQ("12345, rue sans issue, far far lointain, G2R N6C, Oz", f_adresseTest.reqAdresse());

}

