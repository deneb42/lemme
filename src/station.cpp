
#include <iostream>
#include <set>
#include "station.hpp"

using namespace std;

Station::Station(string name)//, string line)
{
    this->nomStation = name;
    //this->listeLignes.insert(line);
    coutTr=(int)nomStation[0];
}

void Station::addSuccesseur(const Station* stat, string ligne) 
{ 
	Transition t(stat, ligne);
	listeSuccesseurs.insert(t); 
}

void Station::afficheStation() const
{
    cout << "Nom de la station : " << nomStation <<endl;
    /*cout << "lignes passant par cette station : " << endl;
    for (set<string>::iterator it = listeLignes.begin(); it != listeLignes.end(); it++) {
        cout << "\t- ligne " << (*it) <<endl;
    }*/
    cout << "Stations suivantes : " << endl;
    for (std::set<Transition>::iterator it = listeSuccesseurs.begin(); it != listeSuccesseurs.end(); it++) {
        cout << "\t- nom de la Station : " << it->getDest()->getName() << "(" << it->getLigne() << ")"<< endl;
    }
    cout << "***********" << endl;
}

double calculerPoidCorrespondance(int age)
{
    return (8.0 + 0.1 * (double) age);
}

bool operator==(const Station& s1, const Station& s2)
{
	return s1.getName()==s2.getName();
}

bool operator<(const Station& s1, const Station& s2)
{
	return s1.getName()<s2.getName();
}

bool operator<(const Transition& t1, const Transition& t2)
{
	return t1.getDest()->getName()<t2.getDest()->getName();
}
