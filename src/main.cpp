#include <iostream>
#include <string>
#include <set>
#include "plan.hpp"

int main()//int argc, char* argv[])
{
	std::string buffer;
    std::string depart, arrivee;
    int heure;
    
    std::cout << "Modelisation du METRO parisien\n\tBADIE Jean & BLOIS Benjamin" << std::endl;
    std::cout << "\nQuel est votre point de depart ?" << std::endl;
    std::cin >> buffer;
    depart = buffer;
    
    std::cout << "\nQuel est votre arrivee ?" << std::endl;
    std::cin >> buffer;
    arrivee = buffer;
    
    std::cout << "\nA quelle heure souhaitez vous partir ? (entier entre 0 et 23)" << std::endl;
    std::cin >> heure;
    //heure = buffer;
    
    std::cout << "\nVous voulez partir de " << depart << " a destination de " << arrivee << " a " << heure <<" heure. \n\tMERCI DE PATIENTER CALCUL EN COURS." << std::endl;
    
    
  /*  int i=10;
	
	Plan p("../data/metro.txt");
	
	for(std::map<std::string, Station>::iterator it=p.getGraphe()->begin();it!=p.getGraphe()->end() && i>0;it++)
	{
		it->second.afficheStation();
		//i--;
	}
	*/
	return 0;
}
