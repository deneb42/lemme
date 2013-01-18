
#include <iostream>
#include <map>
#include <cstdlib>
#include "station.hpp"

/*!
 * \file station.cpp
 * \brief Classe representant une station
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */

using namespace std;

/*!
 * \fn Station
 * \param name, age
 */
Station::Station(string name, int age)
{
    this->nomStation = name;
    ageVoyageur = age;
    coutCh = calculerPoidCorrespondance(ageVoyageur);
}

/*!
 * \fn addSuccesseur
 * \param Station, ligne, heure
 */
void Station::addSuccesseur(Station* stat, string ligne, string heure)
{ 
	Transition t(stat, ligne); t.calculerPoidsTransition(heure);
	listeSuccesseurs.push_back(t);
    coutCh = calculerPoidCorrespondance(ageVoyageur);
}


/*!
 * \fn afficheStation
 */
void Station::afficheStation() const
{
    cout << "Nom de la station : " << nomStation << ", coutmin " << coutMin << " "; 
    if(prec.getDest()!=NULL)
		std::cout << "par : " << prec.getDest()->getName()  << "(" << prec.getLigne() << ") " <<endl;
    cout << "Stations suivantes : " << endl;
    for(auto it = listeSuccesseurs.begin();it!=listeSuccesseurs.end();it++) {
        cout << "\t- nom de la Station : " << it->getDest()->getName() << "(" << it->getLigne() << "), cout:" << it->getTemps() << endl;
    }
    cout << "***********" << endl;
}

/*!
 * \fn afficheStationParParcours
 */
void Station::afficheStationParParcours() const
{
	if(prec.getDest()!=NULL)
		std::cout << "Depuis: " << prec.getDest()->getName() << std::endl;
	std::cout << "  Vers: " << nomStation << " par ligne " << prec.getLigne() << " (" << coutMin << " min)" << endl;
}

/*!
 * \fn calculerPoidCorrespondance
 * \param age
 * \return double
 */
double Station::calculerPoidCorrespondance(int age)
{
    if (this->listeSuccesseurs.size() == 1)
    { //station par laquele ne passe qu'une ligne
        return (8.0 + 0.1 * (double) age);
    }
    if (this->listeSuccesseurs.size() > 1 && this->listeSuccesseurs.size() <= 3)
    { //station par laquele passe de 1 a 3 ligne, on ajoute un coefficient de 10% pour le temps de transfert
        return (8.0 + 0.1 * (double) age) * 1.1;
    }
    else
    { // stations parmis lesquels passe plus de 3 ligne on ajoute
        //un coefficient de 20% de temps de correspondance en plus
        return (8.0 + 0.1 * (double) age) * 1.2;
    }
}


/*!
 * \fn getCoutCh
 * \param ligne
 * \return double
 */
double Station::getCoutCh(std::string ligne)
{
	if(prec.getLigne()==ligne)
		return 0;
	return coutCh;
}

/*!
 * \fn operator==
 * \param Station, Station
 * \return bool
 */
bool operator==(const Station& s1, const Station& s2)
{
	return s1.getName()==s2.getName();
}
