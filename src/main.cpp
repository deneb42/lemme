#include <iostream>
#include <string>
#include <set>
#include "plan.hpp"

int main()//int argc, char* argv[])
{
	string buffer;
    string depart, arrivee, heure;
    
    std::cout << "Modelisation du METRO parisien\n\tBADIE Jean & BLOIS Benjamin" << std::endl;
    std::cout << "\nQuel est votre point de depart ?" << std::endl;
    std::cin >> buffer;
    depart = buffer;
    
    std::cout << "\nQuel est votre arrivee ?" << std::endl;
    std::cin >> buffer;
    arrivee = buffer;
    
    std::cout << "\nA quelle heure souhaitez vous partir ? (entier entre 0 et 23)" << std::endl;
    std::cin >> buffer;
    heure = buffer;
    
    std::cout << "\nVous voulez partir de " << depart << " a destination de " << arrivee << " a " << heure <<" heure. \n\tMERCI DE PATIENTER CALCUL EN COURS." << std::endl;
    
    
  /*  int i=10;
	
	Plan p("../data/metro.txt");
	
	for(std::set<Station>::iterator it=p.graphe.begin();it!=p.graphe.end() && i>0;it++)
	{
		it->afficheStation();
		i--;
	}
	*/
	return 0;
}
