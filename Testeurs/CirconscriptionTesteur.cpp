/*
 * CirconscriptionTesteur.cpp
 *
 *  Created on: 2017-11-30
 *      Author: etudiant
 */

#include <gtest/gtest.h>
#include "Circonscription.h"
#include "Candidat.h"
#include "Electeur.h"
#include <vector>

using namespace elections;

/**
 * \brief Test du Constructeur Circonscription::Circonscription()
 * cas valide :
 * 	ConstructeurParametresValides: Création d'une Circonscription valide
 * cas invalide :
 *  ConstructeurNomInvalide : Nom de Circonscription invalide
 */

TEST(CirconscriptionConstructeur,ConstructeurParametreValides)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	Circonscription uneCirconscription("1", unCandidat);

	ASSERT_EQ("1",uneCirconscription.reqNom());
}

TEST(CirconscriptionConstructeur,ConstructeurNomValides)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	Circonscription uneCirconscription("", unCandidat);

	ASSERT_EQ("",uneCirconscription.reqNom());
}

/**
 * \brief Test de la méthode 	std::string reqCirconscriptionFormate();
 *        cas valide reqCirconscriptionFormate : vérification du retour
 *        cas invalide Aucun d'identifié
 */
TEST(reqFormateMethode, reqCirconscriptionFormate)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	Circonscription uneCirconscription("", unCandidat);

	std::vector<Personne*> m_vInscrits = uneCirconscription.reqVinscrits();

	std::ostringstream os;

	os << "circonscription : Circonscription n0 ";
	os << uneCirconscription.reqNom() << std::endl;
	os << "Depute sortant : " << std::endl;
	os << uneCirconscription.reqDeputeElu() << std::endl;
	os << std::endl;


	os << "Liste des inscrits : " << std::endl;
	os << uneCirconscription.reqDeputeElu() << std::endl;
	os << std::endl;

	for (std::vector<Personne*>::iterator iter1 = m_vInscrits.begin(); iter1 != m_vInscrits.end();++iter1)
		{
			Personne* PersonneAAfficher = *iter1;
			PersonneAAfficher -> reqPersonneFormate();

			std::cout << std::endl;
		}

	ASSERT_EQ(os.str(),uneCirconscription.reqCirconscriptionFormate());
}

/**
 * \brief Test de la méthode void inscrire(const Personne& p_nouvelInscrit)
 * cas valide :
 * Inscrire1ElemPersonneAbsente : Construction, appel de Circonscription::inscrire(), l'élément du dessus est l'élément passé à push.
 * test la methode personneEstDejaPresente() en meme temps pour le cas ou elle ne lest pas et retourne false
 * cas invalide :
 * Inscrire1ElemPersonnePresente : Construction, appel de Circonscription::inscrire(), leve une exception.
 * test la methode personneEstDejaPresente() en meme temps pour le cas ou elle lest et retourne true
 */
TEST(InscrireMethode,Inscrire1ElemPersonneAbsente)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Electeur unElecteur("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse);
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	Circonscription uneCirconscription("", unCandidat);

	uneCirconscription.inscrire(unElecteur);

	std::vector<Personne*> m_vInscrits = uneCirconscription.reqVinscrits();

	ASSERT_EQ(1, m_vInscrits.size());

}

TEST(InscrireMethode,Inscrire1ElemPersonnePresente)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Electeur unElecteur("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse);
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	Circonscription uneCirconscription("", unCandidat);

	uneCirconscription.inscrire(unElecteur);


	ASSERT_THROW(uneCirconscription.inscrire(unElecteur), PersonneDejaPresenteException);

}

/**
 * \brief Test de la méthode void desinscrire(const std::string& p_nas)
 * cas valide :
 * Desinscrire1ElemPersonnePresente : Construction, appel de Circonscription::desinscrire(), l'élément du dessus est l'élément passé à pull.
 * test la methode personneEstDejaPresente() en meme temps pour le cas ou elle lest et retourne true
 * Desinscrire1ElemPersonneAbsente : Construction, appel de Circonscription::desinscrire(), leve une exception.
 * test la methode personneEstDejaPresente() en meme temps pour le cas ou elle ne l'est pas et retourne false
 * cas invalide :
 * PasDelementAdesinscrirePersonneAbsente : appel de Circonscription::desinscrire(), mais le nas de l'électeur qu'on veut supprimer n'existe pas.
 * test la methode personneEstDejaPresente() en meme temps pour le cas ou elle ne lest pas et retourne false
 */
TEST(DesinscrireMethode,Desinscrire1ElemPersonnePresente)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Electeur unElecteur("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse);
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	std::string nasElecteur = unElecteur.reqNas();

	Circonscription uneCirconscription("", unCandidat);

	uneCirconscription.inscrire(unElecteur);

	uneCirconscription.desinscrire(nasElecteur);

	std::vector<Personne*> m_vInscrits = uneCirconscription.reqVinscrits();

	ASSERT_EQ(0, m_vInscrits.size());

}

TEST(DesinscrireMethode,Desinscrire1ElemPersonneAbsente)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Electeur unElecteur("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse);
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	std::string nasElecteur = unElecteur.reqNas();

	Circonscription uneCirconscription("", unCandidat);

	uneCirconscription.inscrire(unElecteur);

	uneCirconscription.desinscrire(nasElecteur);

	ASSERT_THROW(uneCirconscription.desinscrire(nasElecteur), PersonneAbsenteException);


}

TEST(DesinscrireMethode,PasDelementAdesinscrirePersonneAbsente)
{
	util::Date uneDate;
	util::Adresse uneAdresse;
	Electeur unElecteur("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse);
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);

	std::string nasElecteur = unElecteur.reqNas();

	Circonscription uneCirconscription("", unCandidat);

	uneCirconscription.inscrire(unElecteur);

	std::vector<Personne*> m_vInscrits = uneCirconscription.reqVinscrits();

	ASSERT_THROW(uneCirconscription.desinscrire("046 454 000"), PersonneAbsenteException);
}
