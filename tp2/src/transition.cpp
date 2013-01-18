
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include "transition.hpp"

/*!
 * \file Transition.cpp
 * \brief Classe representant une transition entre deux stations
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */

using namespace std;

/*!
 * \fn calculerPoidsTransition
 * \param heure
 */
void Transition::calculerPoidsTransition(std::string heure)
{
    random_device rd;
    if (heure == "creuse")
    { // a ses heures faible traffic (pas de fermeture du réseau la nuit...)                             
		temps = (double) 2.0 + (calculerPoidsVoyageurs( rd()*1000%250 )) / 10000.0;
    }
    else if (heure == "normale")
    { //heure normale
        temps = (double) 2.0 + (calculerPoidsVoyageurs(250 + rd()*1000%150) ) / 10000.0;
    }
    else //heures de pointes de la jounree
    {
        temps = (double) 2.0 + (calculerPoidsVoyageurs(400+rd()*1000%100 )) / 10000.0; //500 capacite max d'une rame de metro parisien.
    }
}

/*!
 * \fn calculerPoidsVoyageurs
 * \param nbPersonnes
 * \return double
 */
double Transition::calculerPoidsVoyageurs(int nbPersonnes)
{
    double poids = 0;
    random_device rd;
    for (int i = 0; i < nbPersonnes; i++) {
        poids += 50 + (rd()*1000%50); //le poid des personne va de 50 à 100kg.
    }
    return poids;
}
