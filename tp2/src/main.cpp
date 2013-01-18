#include <iostream>
#include <string>
#include <set>
#include <list>
#include "plan.hpp"

/*!
* \file main.cpp
* \brief Classe main, gere l'interface utilisateur, et les appels a Dijkstra
* \authors {Jean BADIE, Benjamin BLOIS}
* \date 17 janvier 2013
* 
**/

/*!
 *  \param StationdeDepart, StationDarrivee, TypeD'heure, Anomalie
 *  \return 1 si bonne execution
 */
int main(int argc, char* argv[])
{//par convention si on a 2 arguments on a le point de depart, 3 on a depart et arrivee, 4 l'heure s'y ajoute 5 on a les anomalies.
    
    std::string depart, arrivee, heure, cibleAnom;
    bool anomalie = false, anomLigne; // !anomLigne = anomStation
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
        anomalie = (buffer=="oui");
    }
    else
        anomalie = (std::string(argv[4])=="oui");
    
    if(anomalie)
    {
		if (argc <= 5)
		{
			std::cout << "\nAnomalie de quel type ? (station ou ligne)" << std::endl;
			std::cin >> buffer;
			anomLigne = (buffer == "ligne");

		}
		else
			anomLigne = ("ligne" == std::string(argv[5]));
		
		if (argc <= 6)
		{
			std::cout << "\nCible de l'anomalie (un nom de " << (anomLigne?"ligne ":"station ") << ")" << std::endl;
			std::cin >> cibleAnom;
		}
		else
			cibleAnom = argv[6];
	}
    if(anomalie)
		std::cout << "Avec anomalie sur la " << (anomLigne?"ligne ":"station ") << cibleAnom << std::endl;
	else
		std::cout << "Sans anomalie" << std::endl;
    
    std::cout << "RAPPEL TRAJET\nPoint de départ : " << depart << " Point de d'arrivee : " << arrivee << " type d'heure : " << heure << " avec anomalie : " << anomalie << "\nCALCUL EN COURS" << std::endl;

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
    while (heure != "normale" && heure != "creuse" && heure != "pointe") {
        std::cout << "ERREUR de saisie, a quel moment souhaitez-vous partir ? (creuse, normale, pointe)" << std::endl;
		std::cin >> buffer;
		heure = buffer;

    }
    
    std::cout << "RAPPEL TRAJET\nPoint de départ : " << depart << " Point de d'arrivee : " << arrivee << " type d'heure : " << heure << " avec anomalie : " << anomalie << "\nCALCUL EN COURS" << std::endl;
    
    /* APPEL DE DIJKSTRA */
	std::list<Station*> l = p.dijkstra(&(p.getGraphe()->at(depart)), &(p.getGraphe()->at(arrivee)));

    /* Affichage des stations renvoyees par dijkstra */
	for(std::list<Station*>::iterator it=l.begin();it!=l.end();it++)
		(*it)->afficheStationParParcours();
	
	return 0;
}
