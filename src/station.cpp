
#include <iostream>
#include <map>
#include "station.hpp"

using namespace std;

Station::Station(string name)
{
    this->nomStation = name;
    coutCh=(int)nomStation[0]; // gros hack
}

void Station::addSuccesseur(Station* stat, string ligne) 
{ 
	listeSuccesseurs.insert(pair<std::string, Transition>(stat->getName(), Transition(stat, ligne))); 
}

void Station::afficheStation() const
{
    cout << "Nom de la station : " << nomStation <<endl;
    cout << "Stations suivantes : " << endl;
    for(auto it = listeSuccesseurs.begin();it!=listeSuccesseurs.end();it++) {
        cout << "\t- nom de la Station : " << it->first << "(" << it->second.getLigne() << ")"<< endl;
    }
    cout << "***********" << endl;
}


bool operator==(const Station& s1, const Station& s2)
{
	return s1.getName()==s2.getName();
}
