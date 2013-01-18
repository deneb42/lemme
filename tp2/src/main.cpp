#include <iostream>
#include <string>
#include <set>
#include <list>
#include "plan.hpp"

int main(int argc, char* argv[])
{//par convention si on a 2 arguments on a le point de depart, 3 on a depart et arrivee, 4 l'heure s'y ajoute 5 on a les anomalies.
    
    std::string depart, arrivee, heure;
    bool anomalie = false;
    std::string buffer;
    
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
    std::cout << "Point de départ : " << depart << std::endl;
    
    if (argc <= 2)
    {
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

  /*	
Plan p("../data/metro.txt", heure, anomalie);
	for(std::map<std::string, Station>::iterator it=p.getGraphe()->begin();it!=p.getGraphe()->end();it++)
	{
		it->second.afficheStation();
	}/*
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" <<
				 "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n" <<
				 "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	//std::set<Station*> l1 = p.stationsDsLigne("01");
	std::list<Station*> l = p.dijkstra(&(p.getGraphe()->at("LaDefense-GrandeArche")),
										&(p.getGraphe()->at("Bastille")));
	//for(std::set<Station*>::iterator it=l1.begin();it!=l1.end();it++)
*/

    /* CREATION DU PLAN */
    Plan p("../data/metro.txt", heure, anomalie);
    /* VERIFICATION DES NOMS DES STATIONS */
    while (p.getGraphe()->find(depart) == p.getGraphe()->end()) {
        std::cout << "Gare de départ non trouvee, merci de verifier l'orthographe. D'ou voulez vous partir : ";
        std::cin >> buffer;
        depart = buffer;
    }
    while (p.getGraphe()->find(arrivee) == p.getGraphe()->end()) {
        std::cout << "Gare d'arrivee non trouvee, merci de verifier l'orthographe. Ou voulez vous aller : ";
        std::cin >> buffer;
        arrivee = buffer;
    }
    
    std::cout << "RAPPEL TRAJET\nPoint de départ : " << depart << " Point de d'arrivee : " << arrivee << " type d'heure : " << heure << " avec anomalie : " << anomalie << "\nCALCUL EN COURS" << std::endl;
    
    /* APPEL DE DIJKSTRA */
	std::list<Transition> l = p.dijkstra(&(p.getGraphe()->at(depart)), &(p.getGraphe()->at(arrivee)));

    /* Affichage des stations renvoyees par dijkstra */
	for(std::list<Transition>::iterator it=l.begin();it!=l.end();it++)
		//std::cout << (*it)->getName() << std::endl;
		(*it).getDest()->afficheStation();

	
	return 0;
}
