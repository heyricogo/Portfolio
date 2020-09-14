/**
 * \file PersonneTesteur.cpp
 * \brief Implantation des tests unitaires de la classe Personne
 *        Personne étant une classe abstraite, on crée une classe concrète
 *        dérivée de cette classe afin de pouvoir effectuer les tests
 * \author Eric Cogoluenhes
 */

#include<gtest/gtest.h>
#include "Personne.h"
using namespace elections;

/**
 * \class PersonneDeTest
 * \brief classe de test permettant de tester la classe abstraite Personne
 */
class PersonneDeTest: public Personne
{
public:
	PersonneDeTest(const std::string& p_nas,
			const std::string& p_prenom,
			const std::string& p_nom,
			const util::Date& p_dateNaissance,
			const util::Adresse& p_adresse) :
		Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
	{
	}
	; //instancie un objet Personne
	Personne* clone() const
	{
		return new PersonneDeTest(*this);
	}
	; //doit être implantée car la classe est concrète
	virtual std::string reqPersonneFormate() {
		return Personne::reqPersonneFormate();
	}
	;
};

/**
 * \class UnePersonne
 * \brief Fixture  UnePersonne pour la création d'un objet Personne pour les tests
 */
class UnePersonne: public ::testing::Test
{
public:
	util::Date uneDate;
	util::Adresse uneAdresse;
	UnePersonne() :
		t_personne("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse)
	{
	}
	;

	PersonneDeTest t_personne;
};

/**
 * \brief Test du Constructeur Personne::Personne()
 * cas valide :
 * 	ConstructeurParametresValides: Création d'une Personne valide
 * cas invalide :
 * 	ConstructeurNasInvalide : NAS invalide
 * 	ConstructeurPrenomInvalide : prenom invalide
 * 	ConstructeurNomInvalide : nom invalide
 * 	ConstructeurDateInvalide : Date invalide
 * 	ConstructeurAdresseInvalide : Adresse invalide
 */

TEST(PersonneConstructeur,ConstructeurParametreValides)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	PersonneDeTest unePersonne("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse);

	ASSERT_EQ("046 454 286",unePersonne.reqNas());
	ASSERT_EQ("inconnu",unePersonne.reqNom());
	ASSERT_EQ("inconnu",unePersonne.reqPrenom());
	ASSERT_EQ(uneDate,unePersonne.reqDateNaissance());
}

TEST(PersonneConstructeur,ConstructeurNasInvalide)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	ASSERT_THROW(PersonneDeTest unePersonne("", "inconnu","inconnu", uneDate, uneAdresse),PreconditionException) << "Personne ne prend pas de numero de NAS vide";
}

TEST(PersonneConstructeur,ConstructeurNomInvalide)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	ASSERT_THROW(PersonneDeTest unePersonne("046 454 286", "","inconnu", uneDate, uneAdresse),PreconditionException) << "Personne ne prend pas de numero de NAS vide";
}


TEST(PersonneConstructeur,ConstructeurPrenomInvalide)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	ASSERT_THROW(PersonneDeTest unePersonne("046 454 286", "inconnu","", uneDate, uneAdresse),PreconditionException) << "Personne ne prend pas de numero de NAS vide";
}

/**
 * \class PersonneValide
 * \brief Fixture  PersonneValide pour la création d'un objet Personne pour les tests
 */

class PersonneValide: public ::testing::Test // Une Personne : "046 454 286", "inconnu", "inconnu", uneDate, uneAdresse
{
public:
	util::Date uneDate;
	util::Adresse uneAdresse;
	PersonneValide() :
		f_PersonneTest("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse)
	{

	};

	PersonneDeTest f_PersonneTest;
};

/**
 * \brief Test de la méthode const std::string reqAdresse() const
 *        cas valide reqAdresse: Création Personne et de son adresse valides et test de l'adresse
 *        cas invalide Aucun d'identifié
 */
TEST_F(PersonneValide, reqAdresse)
{
	ASSERT_EQ("1, rue inconnue, inconnue, G1V 0A7, QC", f_PersonneTest.reqAdresse().reqAdresse());

}

/**
 * \brief Test de la méthode void asgAdresse(const util::Adresse& p_adresse)
 *        cas valide reqAdresse: Création Personne et de son adresse valides et test de la modification de l'adresse
 *        cas invalide Aucun d'identifié
 */
TEST_F(PersonneValide, asgAdresse)
{
	util::Adresse nouvelleAdresse;
	f_PersonneTest.asgAdresse(nouvelleAdresse);
	ASSERT_EQ("1, rue inconnue, inconnue, G1V 0A7, QC", f_PersonneTest.reqAdresse().reqAdresse());
}

/**
 * \brief Test de la méthode util::Date reqDateNaissance() const;
 *        cas valide reqDateNaissance: Création Personne et de sa date valides et test de la date
 *        cas invalide Aucun d'identifié
 */
TEST_F(PersonneValide, reqDateNaissance)
{
	ASSERT_EQ(uneDate, f_PersonneTest.reqDateNaissance());
}

/**
 * \brief Test de la méthode const std::string& reqNas() const;
 *        cas valide reqNas: Création Personne et test du Nas
 *        cas invalide Aucun d'identifié
 */
TEST_F(PersonneValide, reqNas)
{
	ASSERT_EQ("046 454 286", f_PersonneTest.reqNas());
}

/**
 * \brief Test de la méthode const std::string& reqNom() const;
 *        cas valide reqNom: Création Personne et test du Nom
 *        cas invalide Aucun d'identifié
 */
TEST_F(PersonneValide, reqNom)
{
	ASSERT_EQ("inconnu", f_PersonneTest.reqNom());
}

/**
 * \brief Test de la méthode const std::string& reqPrenom() const;
 *        cas valide reqPrenom: Création Personne et test du Prenom
 *        cas invalide Aucun d'identifié
 */
TEST_F(PersonneValide, reqPrenom)
{
	ASSERT_EQ("inconnu", f_PersonneTest.reqPrenom());
}





