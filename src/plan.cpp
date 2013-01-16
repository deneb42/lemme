
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
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
		//Station s;
		set<Station>::iterator act, prec;
		getline(ifs, ligne);
		
		//cout << "ligne " << ligne << endl; // traitement pour garder le nom de la ligne
		
		getline(ifs, tmp);
		prec=graphe.insert(tmp); // traitement particulier pour le premier elem, le cast automatique fait appel au constructeur
		getline(ifs, tmp);
		while(!tmp.empty())
		{
			//cout << "ajout de la station " << tmp << " a la ligne " << ligne << endl;
			act=graphe.insert(tmp); // ajout de l'element, s'il est deja present, l'elem existant est retourne
			act.addSuccesseur(prec, ligne);
			prec.addSuccesseur(act, ligne); // on ajoute les liaisons
			prec = act;
			getline(ifs, tmp);
		}
	}
}

/* il manque l'implementation de systemes pour continuer */
void dijkstra(Station *src)
{ /* calcule le poid mini pour aller a toutes les stations depuis la station source */
	set<Station*> visited, *succ = src->getListeSuccesseurs();
	double poidActu=0, min;
	Station *dst;
	
	for(set::iterator it=graphe.begin();it!=graphe.end();it++)
		it->poid=0;
	visited.add(src); // initialisation : on initialise tout les poids a 0 et on visite le noeud source
	
	do
	{
		min= succ->begin()->getCout();
		dst= succ->begin();
		for(set::iterator it=succ->begin();it!=succ->end();it++)
		{
			if(it->poid<min)
			{
				min=it->getCout();
				dst=it;
			}
		}
		visited.add(dst);
		poidActu+=min;
		dst->poid=poidActu;
	}while(visited.size()!=graphe.size)
}
