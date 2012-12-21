
#include <iostream>
#include <set>
#include "station.hpp"

using namespace std;

Station::Station(string name, string line)
{
    this->nomStation = name;
    this->listeLignes.insert(line);
}

void Station::afficheStation()
{
    cout << "Nom de la station : " << nomStation <<endl;
    cout << "lignes passant par cette station : " << endl;
    for (set<string>::iterator it = listeLignes.begin(); it != listeLignes.end(); it++) {
        cout << "\t- ligne " << (*it) <<endl;
    }
    cout << "Stations suivantes : " << endl;
    for (std::set<Station*>::iterator it = listeSuccesseurs.begin(); it != listeSuccesseurs.end(); it++) {
        cout << "\t- nom de la Station : " << (*it)->nomStation << endl;
    }
    cout << "***********" << endl;
}
