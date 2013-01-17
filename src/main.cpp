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
    
    if (argc <= 1)
    {
        //il n'y a aucun argument on les demandes tous
        std::cout << "\nQuel est votre point de départ ?" << std::endl;
		std::cin >> buffer;
		depart = buffer;
    }
    else
      depart = argv[1];  
      
    if (argc <= 2)
    {
        //il y a au moins le point de départ on demande les autres arguments
        std::cout << "\nQuel est votre arrivee ?" << std::endl;
		std::cin >> buffer;
		arrivee = buffer;
    }
    else
        arrivee = argv[2];
    
    if (argc <= 3)
    {//il y a au moins le point de départ et un point d'arrivee on demande les autres arguments
        std::cout << "\nA quel moment souhaitez-vous partir ? (creuse, normale, pointe)" << std::endl;
		std::cin >> buffer;
		heure = buffer;
    }
    else
        heure = argv[3];
        
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
    std::cout << "Point de départ : " << depart << " Point de d'arrivee : " << arrivee << " type d'heure : " << heure << " avec anomalie : " << anomalie << std::endl;

    /*
	std::string stDep, stArr, freq, annom;
	if(argc==1)
	{
		std::cout << argc << std::endl;
		
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
	}
	else if (argc>=5)
	{
		stDep=argv[1]; stArr=argv[2]; freq=argv[3]; annom=argv[4];
	}
	else
	{
		std::cerr << "Erreur : " << argc-1 << ", nombre d'arguments invalide (0 ou au moins 4 demandes)>." << std::endl;
		return 1;
	}*/
	  //*  
	
	
	/*for(std::map<std::string, Station>::iterator it=p.getGraphe()->begin();it!=p.getGraphe()->end();it++)
	{
		it->second.afficheStation();
	}*/
	//std::set<Station*> l1 = p.stationsDsLigne("01");
	p.dijkstra(&p.getGraphe()->at("LaDefense-GrandeArche"));
	//for(std::set<Station*>::iterator it=l1.begin();it!=l1.end();it++)
	//for(std::map<std::string, Station>::iterator it=p.getGraphe()->begin();it!=p.getGraphe()->end();it++)
		//std::cout << (*it)->getName() << std::endl;
<<<<<<< HEAD
		//it->second.afficheStation();
=======
	//	it->second.afficheStation();
>>>>>>> 3902bed38dd2480ab45bfbc06641cbbbf82481d6
	
	// */
	
	return 0;
}
