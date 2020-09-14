#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <string>
#include "Arme.h"


class Personnage
{
    public:
    Personnage();
    Personnage(std::string m_nom); //Constructeur
    Personnage(std::string m_nom, std::string nomArme, int degatsArme); // Constructeur surchargé
    Personnage(std::string m_nom, int vie, int mana, std::string nomArme, int degatsArme); // constructeur surchargé 2
    Personnage(std::string m_nom, int vie, int mana);

    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
    void afficherEtat() const;

    private:

    std::string m_nom;
    int m_vie;
    int m_mana;
    Arme m_arme; //Notre personnage possède une arme
};




#endif // PERSONNAGE_H_INCLUDED
