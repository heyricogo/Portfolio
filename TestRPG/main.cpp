//
//  main.cpp
//  FirstAppPoo
//
//  Created by B�n�ric on 25/06/2014.
//  Copyright (c) 2014 B�n�ric. All rights reserved.
//

#include <iostream>
#include "Personnage.h"
#include "Arme.h"
#include <string>


int main()
{
    Personnage david("David"), goliath("Goliath", "�p�e aiguis�e", 20);
    //Cr�ation de 2 objets de type Personnage : david et goliath

    goliath.attaquer(david); //goliath attaque david
    cout << "Goliath attaque David " << endl;
    david.boirePotionDeVie(20); //david r�cup�re 20 de vie en buvant une potion
    cout << "David boit une potion de vie." << endl;
    goliath.attaquer(david); //goliath attaque � nouveau david
    cout << "Goliath attaque David " << endl;
    david.attaquer(goliath); //david contre-attaque
    cout << "David contre-attaque Goliath " << endl;
    goliath.changerArme("Double hache tranchante v�n�neuse de la mort", 40);
    cout << "Goliath chang d'arme. Il prend une double hache tranchante v�n�neuse de la mort !" << endl;
    goliath.attaquer(david);
    cout << "Goliath attaque David " << endl;

    //Temps mort ! Voyons voir la vie de chacun...
    std::cout << "David" << std::endl;
    david.afficherEtat();
    std::cout << std::endl << "Goliath" << std::endl;
    goliath.afficherEtat();

    return 0;
}

