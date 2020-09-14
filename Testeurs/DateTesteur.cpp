/**
 * \file TesteurDate.cpp
 * \brief Fichier de tests unitaires pour la classe Date
 * \author Administrateur
 * \version 0.1
 * \date 2013-10-09
 * \date dernière modification : 2014-03-12
 */

#include<gtest/gtest.h>
#include <ctime>
#include "Date.h"

using namespace util;
/**
 * \brief Test du constructeur par défaut de Date
 *
 *    cas valide <br>
 *    	ConstructeurParDefaut: Création d'une date à l'aide du constructeur par défaut
 *        et d'une autre avec la fonction time, elles doivent être égales
 *        <br>
 *    cas invalide <br>
 *    	aucun d'identifié.
 */

TEST(Date, ConstructeurParDefaut)
{
	Date aujourdhui;
	time_t m_temps = time(NULL);
	struct tm* infoTempsP = localtime(&m_temps);
	EXPECT_EQ(infoTempsP->tm_mday, aujourdhui.reqJour())
			<< "reqJour devrait retourner " << infoTempsP->tm_mday;
	EXPECT_EQ(infoTempsP->tm_mon + 1,aujourdhui.reqMois())
			<< "reqMois devrait retourner " << infoTempsP->tm_mon + 1;
	EXPECT_EQ(infoTempsP->tm_year + 1900,aujourdhui.reqAnnee())
			<< "reqAnnee devrait retourner " << infoTempsP->tm_year + 1900;
}
/**
 * \brief Test du constructeur avec paramètres de Date::Date(long, long, long)
 *
 *        cas valide :
 *          Création d'une date valide : ParametresValides
 *
 *        cas invalides :
 *        	jour invalide -> ParametreJourInvalide,
 *        	mois invalide : ParametreMoisInvalide,
 *        	annee invalide : ParametreAnneeInvalide,
 *        	jour+mois+année invalides : ParametreDateInvalide
 */

TEST(Date, ParametresValides)
{
	Date dateTest(10, 4, 2011);
	ASSERT_EQ(10, dateTest.reqJour());
	ASSERT_EQ(4, dateTest.reqMois());
	ASSERT_EQ(2011, dateTest.reqAnnee());
}

// jour invalide
TEST(Date, ParametreJourInvalide)
{

	ASSERT_THROW(Date d1(50,2,2011), PreconditionException);
}
// mois invalide
TEST(Date, ParametreMoisInvalide)
{
	ASSERT_THROW(Date d2(1,13,2011), PreconditionException);
}
// année invalide
TEST(Date, ParametreAnneeInvalide)
{
	ASSERT_THROW(Date d3(1,3,1965), PreconditionException);
}
// date invalide
TEST(Date, ParametreDateInvalide)
{
	ASSERT_THROW(Date d3(29,02,2011), PreconditionException);

}

/**
 * \class DateLongLongLong
 * \brief Fixture pour les tests sur une date
 */

class DateLongLongLong: public ::testing::Test // Une date 10/4/2011
{
public:
	DateLongLongLong() :
			f_dateTest(10, 4, 2011)
	{
	}
	;

	Date f_dateTest;
};

/**
 * \brief Test de la méthode bool Date::ajouteNbJour(long)
 *   cas valide
 *     	AjouteNbJourDsLimites:Ajout d'un certain nombre de jours à l'intérieur des limites.
 *   	AjouteNbJourNegatifDsLimites:Ajout d'un certain nombre de jours (négatif) à l'intérieur des limites.
 *      AjouteNbJourPasDsLimites:Ajout d'un jour menant à l'extérieur des limites, doit retourner faux
 *   	AjouteNbJourNegatifPasDsLimites:Ajout d'un jour (négatif) menant à l'extérieur des limites, doit retourner faux
 *    cas invalide Aucun d'identifié.
 */
TEST_F(DateLongLongLong, AjouteNbJourDsLimites)
{
	f_dateTest.ajouteNbJour(5);
	ASSERT_EQ(15, f_dateTest.reqJour());
	ASSERT_EQ(4, f_dateTest.reqMois());
	ASSERT_EQ(2011, f_dateTest.reqAnnee());
}

TEST_F(DateLongLongLong, AjouteNbJourNegatifDsLimites)
{
	f_dateTest.ajouteNbJour(-5);
	ASSERT_EQ(5, f_dateTest.reqJour());
	ASSERT_EQ(4, f_dateTest.reqMois());
	ASSERT_EQ(2011, f_dateTest.reqAnnee());
}

TEST(DateLimite, AjouteNbJourPasDsLimites)
{
	Date d(31, 12, 2037);
	ASSERT_FALSE(d.ajouteNbJour(1));
}

TEST(DateLimite, AjouteNbJourNegatifPasDsLimites)
{
	Date d(1, 1, 1970);
	ASSERT_FALSE(d.ajouteNbJour(-1));
}
/**
 * \brief Test de la méthode long Date::asgDate()
 *     	cas valide
 *     		AsgDateValide: Assigner une date avec un jour, un mois et une année valides
 *   	cas invalides
 *        	jour invalide : AsgJourInvalide
 *        	mois invalide : AsgMoisInvalide
 *        	annee invalide : AsgAnneeInvalide
 *        	jour+mois+année invalides : AsgDateInvalide
 */
TEST_F(DateLongLongLong, AsgDateValide)
{
	f_dateTest.asgDate(12, 12, 2013);
	ASSERT_EQ(12, f_dateTest.reqJour());
	ASSERT_EQ(12, f_dateTest.reqMois());
	ASSERT_EQ(2013, f_dateTest.reqAnnee());
}
//cas invalides
// jour invalide
TEST_F(DateLongLongLong, AsgJourInvalide)
{
	ASSERT_THROW(f_dateTest.asgDate(50, 2, 2011), PreconditionException);
}
// mois invalide
TEST_F(DateLongLongLong, ParametreMoisInvalide)
{
	ASSERT_THROW(f_dateTest.asgDate(1, 13, 2011), PreconditionException);
}
// année invalide
TEST_F(DateLongLongLong, AsgAnneeInvalide)
{
	ASSERT_THROW(f_dateTest.asgDate(1, 3, 1965), PreconditionException);
}
// date invalide
TEST_F(DateLongLongLong, AsgDateInvalide)
{
	ASSERT_THROW(f_dateTest.asgDate(29, 02, 2011), PreconditionException);
}

/**
 * \brief Test de la méthode long Date::reqJour()
 *        cas valide reqJour: Création date valide connue et test du jour
 *        cas invalide Aucun d'identifié
 */
TEST_F(DateLongLongLong, reqJour)
{
	ASSERT_EQ(10, f_dateTest.reqJour());
}
/**
 * \brief Test de la méthode long Date::reqMois()
 *        cas valide reqMois: Création date valide connue et test du mois
 *        cas invalide Aucun d'identifié
 */TEST_F(DateLongLongLong, reqMois)
{
	ASSERT_EQ(4, f_dateTest.reqMois());
}
/**
 * \brief  Test de la méthode long Date::reqAnnee()
 *        cas valide reqAnnee: Création date valide connue et test de l'année
 *        cas invalide Aucun d'identifié
 */TEST_F(DateLongLongLong, reqAnnee)
{
	ASSERT_EQ(2011, f_dateTest.reqAnnee());
}
/**
 * \brief Test de la méthode long Date::reqJourAnnee()
 *        cas valide
 *   		getJourAnneePremierJr: Date valide le 1er jour de l'année
 *  		getJourAnneeBissextile Date valide le dernier jour d'une année bissextile
 *        cas invalide Aucun d'identifié
 */TEST(DateReqJourAnnee, reqJourAnneePremierJour)
{
	Date d(1, 1, 2001);
	ASSERT_EQ(1, d.reqJourAnnee());
}

TEST(DateReqJourAnnee, reqJourAnneeBissextile)
{
	Date d(31, 12, 2000);
	ASSERT_EQ(366, d.reqJourAnnee());
}
/**
 * \brief  Test de la méthode std::string Date::reqDateFormatee()
 *        cas valide DateFormatee: Date connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(DateLongLongLong, DateFormatee)
{
	ASSERT_EQ("Dimanche le 10 avril 2011", f_dateTest.reqDateFormatee());
}

/**
 * \class DeuxDates
 * \brief Fixture pour les tests comparaisons de Deux dates
 */
class DeuxDates: public ::testing::Test
{
public:
	static const int valeur = 1;
	DeuxDates() :
			f_date1(15, 4, 2000), f_date2(16, 4, 2010)
	{
	}
	;

	Date f_date1;
	Date f_date2;
};
/**
 * \brief  Test de la méthode bool Date::operator== (const Date& obj)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Date indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Dates différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxDates, OperatorEgalEgalVrai)
{
	ASSERT_EQ(f_date1, f_date1);
}

TEST_F(DeuxDates, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(f_date1 == f_date2); // On ne peut utiliser ASSERT_NE() si l'opérateur != n'est pas implémenté
}
/**
 * \brief  Test de la méthode bool Date::operator< (const Date& obj)
 *        cas valide:
 *   		OperatorPlusPetitFaux: Date indentique à elle-même.
 *  		OperatorPlusPetitVrai: Dates différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxDates, OperatorPlusPetitVrai)
{
	ASSERT_TRUE(f_date1 < f_date2);
}

TEST_F(DeuxDates, OperatorPlusPetitFaux)
{
	ASSERT_FALSE(f_date2 < f_date1);
}
/**
 * \brief  Test de la méthode double Date::operator- (const Date& obj)
 *        cas valide:
 *         OperatorDatesSup: 		Date supérieure
 *         OperatorDatesInf: 		Date inférieure
 *         OperatorDatesEgales: 	Dates égales
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxDates, OperatorDatesSup)
{
	ASSERT_EQ(3653, f_date2 - f_date1);
}

TEST_F(DeuxDates, OperatorDatesInf)
{
	ASSERT_EQ(-3653, f_date1 - f_date2);
}

TEST_F(DeuxDates, OperatorDatesEgales)
{
	ASSERT_EQ(0, f_date1 - f_date1);
}
/**
 * \brief  Test de la méthode bool Date::estBissextile(long annee)
 *        cas valide:
 *  		EstBissextile: 		Année bissextile      2000
 * 		    NEstPasBissextile: 	Année non bissextile  1900
 *        cas invalide Aucun d'identifié
 */
TEST(DateBissextile, EstBissextile)
{
	ASSERT_TRUE(Date::estBissextile(2000));
}

TEST(DateBissextile, NEstPasBissextile)
{
	ASSERT_FALSE(Date::estBissextile(1900));
}

/**
 * \brief  Test de la méthode bool Date::validerDate(long jour, long mois, long annee)
 * 	cas valide:
 *   	EstValide: Vérifier une date valide, p.e. 1 mars 2001
 *   	JourInvalide : Vérifier un jour invalide, p.e. 32
 *   	MoisInvalide : Vérifier une année invalide, p.e. 13
 *   	AnneeInvalideInf : Vérifier une année invalide, p.e. avant 1970
 *   	AnneeInvalideSup : Vérifier une année invalide, p.e. après 2037
 *   	DateInvalide : Vérifier une date invalide (jour+mois+année), p.e. 29 février 1981
 * 	cas invalide Aucun d'identifié
 */

TEST(DateValidee, EstValide)
{
	ASSERT_TRUE(Date::validerDate(1, 3, 2001));
}

TEST(DateValidee, JourInvalide)
{
	ASSERT_FALSE(Date::validerDate(32, 3, 1985));
}

TEST(DateValidee, MoisInvalide)
{
	ASSERT_FALSE(Date::validerDate(1, 32, 1985));
}

TEST(DateValidee, AnneeInvalideInf)
{
	ASSERT_FALSE(Date::validerDate(1, 3, 1965));
}

TEST(DateValidee, AnneeInvalideSup)
{
	ASSERT_FALSE(Date::validerDate(1, 3, 2038));
}

TEST(DateValidee, DateInvalide)
{
	ASSERT_FALSE(Date::validerDate(29, 2, 1981));
}

/**
 * \brief  Test de la méthode ostream& Date::operator<<(ostream&, const Date&)
 * 	cas valide:
 *  	OperatorPlusPetitPlusPetit: Date valide connue qu'on envoie dans un ostringstream
 *  	et qu'on compare avec la sortie prévue.
 * 	cas invalide Aucun d'identifié
 */
TEST_F(DateLongLongLong, OperatorPlusPetitPlusPetit)
{
	std::ostringstream os;
	os << f_dateTest;
	ASSERT_EQ("10/04/2011",os.str());
}
