
/*!
 * \file station.cpp
 * \brief Classe representant une station
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */
 
#include <map>
#include <cstdlib>
#include <limits>

#include "station.hpp"


/*!
 * \fn Station
 * \param name, age
 */
Station::Station(std::string name, int age)
{
    this->nomStation = name;
    ageVoyageur = age;
    coutCh = calculerPoidCorrespondance(ageVoyageur);
    coutMin=std::numeric_limits<double>::infinity();
    prec = Transition();
}

/*!
 * \fn addSuccesseur
 * \param Station, ligne, heure
 */
void Station::addSuccesseur(Station* stat, std::string ligne, std::string heure)
{ 
	Transition t(stat, ligne); t.calculerPoidsTransition(heure);
	listeSuccesseurs.push_back(t);
    coutCh = calculerPoidCorrespondance(ageVoyageur);
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
 * \fn stringStationParParcours
 */
std::string Station::stringStationParParcours() const
{
	std::string str("");
	
	if(prec.getDest()!=NULL)
		str+= "Depuis: " + prec.getDest()->getName() + "\n";
	str+= "  Vers: " + nomStation + " par ligne " + prec.getLigne() + " (" + std::to_string(coutMin) + " min)\n";
	
	return str;
}

/*!
 * \fn afficheStation
 */
std::string Station::toString() const
{
	std::string str("Nom de la station : ");
	str+= nomStation + ", coutmin " + std::to_string(coutMin) + " "; 
    if(prec.getDest()!=NULL)
		str+= "par : " + prec.getDest()->getName() + "(" + prec.getLigne() + ")\n";
    str+= "Stations suivantes : \n";
    for(auto it = listeSuccesseurs.begin();it!=listeSuccesseurs.end();it++)
        str+= "\t- nom de la Station : " + it->getDest()->getName() + "(" + it->getLigne() + "), cout:" + std::to_string(it->getTemps()) + "\n";
        
    str+= "***********\n";
    return str;
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
