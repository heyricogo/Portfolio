/*
 * programmePrincipal.cpp
 *
 *  Created on: 2017-10-18
 *      Author: etudiant
 */

#include "Date.h"
#include "Personne.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Circonscription.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace elections;


int main()
{
	int choix = 0;
	int parti = 0;

	std::cout << "Bienvenue a l'outil de gestion des listes électorales " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;

	bool valide;
	bool dateValide = true;
	bool termine = false;

	std::string nas;
	std::string nom;
	std::string prenom;
	std::string nomFichierSauvegarde;

	int nbRue;
	std::string nomRue;
	std::string nomVille;
	std::string codePostal;
	std::string province;

	util::Date dateNaissance;
	util::Adresse adresse;

	long jour;
	long mois;
	long annee;

	util::Date uneDate;
	util::Adresse uneAdresse;
	Candidat unCandidat("046 454 286", "inconnu", "inconnu", uneDate, uneAdresse, 3);
	Circonscription NotreCirconscription("1",unCandidat);

	do
	{
		std::cout << "Votre choix ? :" << std::endl;
		std::cout << "1.inscription d'un candidat" << std::endl;
		std::cout << "2.inscription d'un electeur" << std::endl;
		std::cout << "3.affichage de la circonscription" << std::endl;
		std::cout << "4.quitter" << std::endl;

		std::cin >> choix;

		switch (choix)
			{
			case 1:
				std::cout << "Choississez un parti :" << std::endl;
				std::cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << std::endl;
				std::cin >> parti;
				std::cout << std::endl;
				do
					{
						std::cout << "Veuillez entrer sa date de naissance" << std::endl;
						std::cout << "Le jour [1..31] : ";
						std::cin >> jour;
						std::cout << std::endl;
						std::cout << "Le mois [1..12] :";
						std::cin >> mois;
						std::cout << std::endl;
						std::cout << "L'année [1970..2037] :";
						std::cin >> annee;
						std::cout << std::endl;

						if (!dateValide)
						{
							std::cout << "La date de naissance n'est pas valide." << std::endl;
							std::cout << std::endl;
							dateValide = false;
						} else
							dateValide = true;

					} while(!dateNaissance.validerDate(jour,mois,annee));

				std::cout << std::endl;
				std::cin.ignore();
				std::cout << "No de rue :";
				std::cin >> nbRue;
				std::cout << std::endl;
				std::cout << "Rue :";
				std::cin.ignore();
				char buffer[256];
				std::cin.getline(buffer, 255);
				nomRue = buffer;
				std::cout << std::endl;
				std::cout << "Ville :";
				std::cin.ignore();
				std::cin.getline(buffer, 255);
				nomVille = buffer;
				std::cout << std::endl;
				std::cout << "Code postal :";
				std::cin.ignore();
				std::cin.getline(buffer, 255);
				codePostal = buffer;
				std::cout << std::endl;
				std::cout << "Province :";
				std::cin.ignore();
				std::cin.getline(buffer, 255);
				province = buffer;
				std::cout << std::endl;
				std::cout << "Entrez son numéro d'assurance sociale" << std::endl;
				std::cin.getline(buffer, 255);
				nas = buffer;

				do
				{
					std::cout << "Entrez le nom" << std::endl;
					char buffer[256];
					std::cin.getline(buffer, 255);
					nom = buffer;
					if(nom =="")
					{
						std::cout << "Le nom est vide" << std::endl;
						std::cout << std::endl;
						valide = false;
					} else
					{
						valide = true;
					}
				} while (!valide);

				do
				{
					std::cout << "Entrez le prénom" << std::endl;
					char buffer[256];
					std::cin.getline(buffer, 255);
					prenom = buffer;
					if(prenom =="")
					{
						std::cout << "Le prénom est vide" << std::endl;
						std::cout << std::endl;
						valide = false;
					} else
					{
						valide = true;
					}
				} while (!valide);
				termine = false;
				break;
			case 2:
				do
				{
					std::cout << "Veuillez entrer sa date de naissance" << std::endl;
					std::cout << "Le jour [1..31] : ";
					std::cin >> jour;
					std::cout << std::endl;
					std::cout << "Le mois [1..12] :";
					std::cin >> mois;
					std::cout << std::endl;
					std::cout << "L'année [1970..2037] :";
					std::cin >> annee;
					std::cout << std::endl;

					if (!dateValide)
					{
						std::cout << "La date de naissance n'est pas valide." << std::endl;
						std::cout << std::endl;
						dateValide = false;
					} else
						dateValide = true;

				} while(!dateNaissance.validerDate(jour,mois,annee));

			std::cout << std::endl;
			std::cin.ignore();
			std::cout << "No de rue :";
			std::cin >> nbRue;
			std::cout << std::endl;
			std::cout << "Rue :";
			std::cin.ignore();
			std::cin.getline(buffer, 255);
			nomRue = buffer;
			std::cout << std::endl;
			std::cout << "Ville :";
			std::cin.ignore();
			std::cin.getline(buffer, 255);
			nomVille = buffer;
			std::cout << std::endl;
			std::cout << "Code postal :";
			std::cin.ignore();
			std::cin.getline(buffer, 255);
			codePostal = buffer;
			std::cout << std::endl;
			std::cout << "Province :";
			std::cin.ignore();
			std::cin.getline(buffer, 255);
			province = buffer;
			std::cout << std::endl;
			std::cout << "Entrez son numéro d'assurance sociale" << std::endl;
			std::cin.getline(buffer, 255);
			nas = buffer;

			do
			{
				std::cout << "Entrez le nom" << std::endl;
				char buffer[256];
				std::cin.getline(buffer, 255);
				nom = buffer;
				if(nom =="")
				{
					std::cout << "Le nom est vide" << std::endl;
					std::cout << std::endl;
					valide = false;
				} else
				{
					valide = true;
				}
			} while (!valide);

			do
			{
				std::cout << "Entrez le prénom" << std::endl;
				char buffer[256];
				std::cin.getline(buffer, 255);
				prenom = buffer;
				if(prenom =="")
				{
					std::cout << "Le prénom est vide" << std::endl;
					std::cout << std::endl;
					valide = false;
				} else
				{
					valide = true;
				}
			} while (!valide);
				termine = false;
				break;
			case 3:
				NotreCirconscription.reqCirconscriptionFormate();
				termine = false;
				break;
			case 4:
				std::cout << "fin du programme" << std::endl;
				termine = true;
				break;
			}
		Candidat NotreCandidat(nas, prenom, nom, dateNaissance, adresse, parti);
		NotreCirconscription.inscrire(NotreCandidat);

		} while(!termine);

	return 0;
}
