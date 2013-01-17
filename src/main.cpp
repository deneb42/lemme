#include <iostream>
#include <string>
#include <set>
#include "plan.hpp"

int main(int argc, char* argv[])
{//par convention un argument on a le point de depart, 2 on a depart et arrivee, 3 l'ehure s'y ajoute 4 on a les anomalies.
    
    std::string depart, arrivee, heure;
    bool anomalie = false;
    std::string buffer;
    
    Plan p("../data/metro.txt");
    std::cout << "Modelisation du METRO parisien\n\tBADIE Jean & BLOIS Benjamin" << std::endl;
    
    std::cout << "argc : " << argc << std::endl;
    
    if (argc <= 1)
    {
        std::cout << "argc <= 1" <<std::endl;
        //il n'y a aucun argument on les demandes tous
        std::cout << "\nQuel est votre point de départ ?" << std::endl;
		std::cin >> buffer;
		depart = buffer;
    }
    else  
    	depart = argv[1];
    std::cout << "Point de départ : " << depart << std::endl;
    
    if (argc <= 2)
    {
        std::cout << "argc <= 2" <<std::endl;
        //il y a au moins le point de départ on demande les autres arguments
        std::cout << "\nQuel est votre arrivee ?" << std::endl;
		std::cin >> buffer;
		arrivee = buffer;
    }
    else
        arrivee = argv[2];
    std::cout << "Station de destination : " << arrivee << std::endl;
    
    if (argc <= 3)
    {//il y a au moins le point de départ et un point d'arrivee on demande les autres arguments
        std::cout << "\nA quel moment souhaitez-vous partir ? (creuse, normale, pointe)" << std::endl;
		std::cin >> buffer;
		heure = buffer;
    }
    else
        heure = argv[3];
    std::cout << "Moment de la journee : " << heure << std::endl;
    
    if (argc <= 4)
    {//il y a au moins le point de départ et un point d'arrivee et heure on demande les autres arguments
        std::cout << "\nSouhaitez vous une anomalie ? (oui ou non)" << std::endl;
		std::cin >> buffer;
        if (buffer.compare("oui")) {
            anomalie = true;
        }
    }
    else
    {
        buffer = argv[4];
        if (buffer.compare("oui")) {
            anomalie = true;
        }
    }
    std::cout << "Avec anomalie ? " << anomalie << std::endl;
    
    std::cout << "RAPPEL TRAJET\nPoint de départ : " << depart << " Point de d'arrivee : " << arrivee << " type d'heure : " << heure << " avec anomalie : " << anomalie << "\nCALCUL EN COURS" << std::endl;

  	
	
	/*for(std::map<std::string, Station>::iterator it=p.getGraphe()->begin();it!=p.getGraphe()->end();it++)
	{
		it->second.afficheStation();
	}*/
	//std::set<Station*> l1 = p.stationsDsLigne("01");
	//p.dijkstra(&p.getGraphe()->at("LaDefense-GrandeArche"));
	//for(std::set<Station*>::iterator it=l1.begin();it!=l1.end();it++)
	//for(std::map<std::string, Station>::iterator it=p.getGraphe()->begin();it!=p.getGraphe()->end();it++)
		//std::cout << (*it)->getName() << std::endl;
		//it->second.afficheStation();

	
	// */
	
	return 0;
}
