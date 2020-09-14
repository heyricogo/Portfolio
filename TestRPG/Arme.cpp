//
//  Arme.cpp
//  FirstAppPoo
//
//  Created by B�n�ric on 28/06/2014.
//  Copyright (c) 2014 B�n�ric. All rights reserved.
//

#include "Arme.h"

using namespace std;

Arme::Arme() : m_nom("�p�e rouill�e"), m_degats(10)
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
    cout << "Arme : " << m_nom << " (D�gats : " << m_degats << ")" << endl;
}
