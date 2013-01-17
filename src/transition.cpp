
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include "transition.hpp"

using namespace std;

double Transition::calculerPoidsTransition(int heure)
{
    if ((heure <= 0 && heure > 7) || (heure <= 9 && heure > 12) || (heure <= 13 && heure > 17) || (heure <= 19 && heure > 23) )
    { // a ses heures faible traffic (pas de fermeture du réseau la nuit...)                             
        return 2.0 + (calculerPoidsVoyageurs(60) / 10000.0);
    }
    else //heures de pointes de la jounree
    {
        return 2.0 + (calculerPoidsVoyageurs(650) / 10000.0); //650 capacite max d'une rame de metro parsien.
    }
}

double Transition::calculerPoidsVoyageurs(int nbPersonnes)
{
    double poids = 0;
    random_device rd;
    for (int i = 0; i < nbPersonnes; i++) {
        poids += 50 + (rd() * 100000 % 50);
    }
    return poids;
}
