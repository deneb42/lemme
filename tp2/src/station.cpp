
#include <iostream>
#include <map>
#include <cstdlib>
#include "station.hpp"

using namespace std;

Station::Station(string name, int age)
{
    this->nomStation = name;
    ageVoyageur = age;
    coutCh = calculerPoidCorrespondance(ageVoyageur);
    //   coutCh=(int)nomStation[0]; // gros hack
}

void Station::addSuccesseur(Station* stat, string ligne, string heure)
{ 
	Transition t(stat, ligne); t.calculerPoidsTransition(heure);
	//t.poid=coutCh+listeSuccesseurs.size();
	listeSuccesseurs.push_back(t);
    coutCh = calculerPoidCorrespondance(ageVoyageur);
}

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

void Station::afficheStationParParcours() const
{
    cout << "Depuis " << (prec==NULL?"*":prec->getName()) << " en direction de " << nomStation << " temps : " << coutCh << " min." << endl;

    /*
    cout << "Nom de la station : " << nomStation << ", coutmin " << coutMin << " par : " << (prec==NULL?"*":prec->getName()) <<endl;
    cout << "Stations suivantes : " << endl;
    for(auto it = listeSuccesseurs.begin();it!=listeSuccesseurs.end();it++) {
        cout << "\t- nom de la Station : " << it->first << "(" << it->second.getLigne() << "), cout:" << it->second.getTemps() << endl;
    }
    cout << "***********" << endl;*/
}

double Station::calculerPoidCorrespondance(int age)
{
    if (this->listeSuccesseurs.size() == 1)
    { //station par laquele ne passe qu'une ligne
        return (8.0 + 0.1 * (double) age);
    }
    if (this->listeSuccesseurs.size() > 1 && this->listeSuccesseurs.size() <= 3)
    { //station par laquele passe de 1 a 3 ligne, on ajoute un coefficient de 10% pour le temps de transfert
        return (8.0 + 0.1 * (double) age) * 1,1;
    }
    else
    { // stations parmis lesquels passe plus de 3 ligne on ajoute
        //un coefficient de 20% de temps de correspondance en plus
        return (8.0 + 0.1 * (double) age) * 1,2;
    }
    return (8.0 + 0.1 * (double) age);
}

bool operator==(const Station& s1, const Station& s2)
{
	return s1.getName()==s2.getName();
}
