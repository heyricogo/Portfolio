//
//  Arme.cpp
//  FirstAppPoo
//
//  Created by Bénéric on 28/06/2014.
//  Copyright (c) 2014 Bénéric. All rights reserved.
//

#include "Arme.h"

using namespace std;

Arme::Arme() : m_nom("Épée rouillée"), m_degats(10)
{

}

Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{

}


int Arme::getDegats() const
{
    return m_degats;
}

void Arme::changer(string nom, int degats)
{
    m_nom = nom;
    m_degats = degats;
}

void Arme::afficher() const
{
    cout << "Arme : " << m_nom << " (Dégats : " << m_degats << ")" << endl;
}
