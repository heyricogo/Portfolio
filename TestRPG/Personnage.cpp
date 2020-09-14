//
//  Personnage.cpp
//  FirstAppPoo
//
//  Created by Bénéric on 25/06/2014.
//  Copyright (c) 2014 Bénéric. All rights reserved.
//

#include "Personnage.h"

using namespace std;

Personnage::Personnage(string m_nom): m_vie(100), m_mana(100)
{

}

Personnage::Personnage(string m_nom, string nomArme, int degatsArme): m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{

}

Personnage::Personnage(string m_nom, int vie, int mana, string nomArme, int degatsArme) : m_vie(vie), m_mana(mana), m_arme(nomArme, degatsArme)
{

}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
    //On enlève le nombre de dégats reçus à la vie du personnage

    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
    //On inflige à la cible les dégats que cause notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdicton de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant()
{
    return m_vie > 0; //renvoie true si m_vie > 0 et false sinon

    /*if (m_vie > 0) //Plus de 0 de vie ?
    {
        return true; //VRAI, il est vivant !!!
    }
    else
    {
        return false; //FAUX, il est mort !!!
    }*/
}

void Personnage::afficherEtat() const
{
    cout << "Nom : " << m_nom << endl;
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}

