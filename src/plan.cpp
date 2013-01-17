
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <set>
#include "plan.hpp"

using namespace std;

Plan::Plan(string path)
{
	ifstream ifs(path.c_str());
	string tmp, ligne;
	
	if(!ifs.good()) {
		cerr << "erreur a l'ouverture du fichier" << endl;
		exit(1);
	}
	while(!ifs.eof())
	{
		map<std::string, Station>::iterator act, prec;

		getline(ifs, ligne);
		//cout << "ligne " << ligne << endl; // traitement pour garder le nom de la ligne
		
		getline(ifs, tmp);
		prec=graphe.insert(pair<string, Station>(tmp, Station(tmp))).first; // traitement particulier pour le premier elem, le cast automatique fait appel au constructeur
		debLignes.insert(pair<string, Station*>(ligne, &(prec->second)));
		getline(ifs, tmp);
		while(!tmp.empty())
		{
			//cout << "ajout de la station " << tmp << " a la ligne " << ligne << endl;
			act=graphe.insert(pair<string, Station>(tmp, Station(tmp))).first; // ajout de l'element, s'il est deja present, l'elem existant est retourne
			act->second.addSuccesseur(&(prec->second), ligne);
			prec->second.addSuccesseur(&(act->second), ligne); // on ajoute les liaisons
			prec = act;
			getline(ifs, tmp);
		}
	}
}

/* il manque l'implementation de systemes pour continuer */
void Plan::dijkstra(Station *s)
{ // calcule le poid mini pour aller a toutes les stations depuis la station source
	Station *src=s, *dst;
	set<Station*> visited;
	map<std::string, Transition> succ = src->getListeSuccesseurs();
	double poidActu=0, min;
	
	for(map<std::string, Station>::iterator it=graphe.begin();it!=graphe.end();it++)
		it->second.setCoutMin(0);
	visited.insert(src); // initialisation : on initialise tout les poids a 0 et on visite le noeud source
	src->setPrec(NULL);
	
	do
	{
		min= numeric_limits<double>::infinity(); // a tester ou numeric_limits<float>::infinity()
		for(map<std::string, Transition>::iterator it=succ.begin();it!=succ.end();it++)
		{
			if(it->second.poid<min)
			{
				min=it->second.poid;
				dst=it->second.getDest();
			}
		}
		visited.insert(dst);
		poidActu+=min;
		dst->setCoutMin(poidActu);
		dst->setPrec(src);
		src=dst;
	}while(visited.size()!=graphe.size());
}// */


// trouve les differentes stations d'une ligne
std::set<Station*> Plan::stationsDsLigne(std::string ligne)
{
	std::set<Station*> visite;
	Station* act = debLignes[ligne];
	bool ok;
	
	visite.insert(act);
	do {
		ok=false;
		std::map<std::string, Transition> succ = act->getListeSuccesseurs();
		for(std::map<std::string, Transition>::iterator it2=succ.begin();
			 it2!=succ.end() && !ok;it2++)
		{
			if(it2->second.getLigne()==ligne)
			{	
				if(visite.insert(it2->second.getDest()).second) // si pas trouve
				{
					act=it2->second.getDest();
					ok=true;
				}
			}
		}
	}while(ok);
	
	return visite;
} 
