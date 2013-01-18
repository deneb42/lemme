#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <set>
#include <list>
#include <random>
#include "plan.hpp"

using namespace std;


Plan::Plan(string path, string heure, bool anomalie)
{
    // GENERATION DE L'AGE DU VOYAGEUR
    random_device rd;
    int age = 7 + rd()*10000%80; // un voyageur a de 7 a 87 ans.
    cout << "age : " << age << endl;
    // TODO Modif signatures appel creation stations et transitions.
    
    
	ifstream ifs(path.c_str());
	string tmp, ligne;
	int pos;
	
	if(!ifs.good()) {
		cerr << "erreur a l'ouverture du fichier" << endl;
		exit(1);
	}
	ws(ifs);
	while(!ifs.eof())
	{
		map<std::string, Station>::iterator act, prec;
		
		getline(ifs, ligne);
		if((pos=ligne.find_first_of(" \t"))!=std::string::npos)
			ligne.erase(pos); // to get rid of whitespace
		//cout << "ligne " << ligne << endl; // traitement pour garder le nom de la ligne
		
		getline(ifs, tmp);
		if((pos=tmp.find_first_of(" \t"))!=std::string::npos)
			tmp.erase(pos); // to get rid of whitespace
		prec=graphe.insert(pair<string, Station>(tmp, Station(tmp, age))).first; // traitement particulier pour le premier elem, le cast automatique fait appel au constructeur
		debLignes.insert(pair<string, Station*>(ligne, &(prec->second)));
		
		getline(ifs, tmp);
		if((pos=tmp.find_first_of(" \t"))!=std::string::npos)
			tmp.erase(pos); // to get rid of whitespace
		while(!tmp.empty())
		{
			//cout << "ajout de la station " << tmp << " a la ligne " << ligne << endl;
			act=graphe.insert(pair<string, Station>(tmp, Station(tmp, age))).first; // ajout de l'element, s'il est deja present, l'elem existant est retourne
			act->second.addSuccesseur(&(prec->second), ligne, heure);
			prec->second.addSuccesseur(&(act->second), ligne, heure); // on ajoute les liaisons
			prec = act;
			getline(ifs, tmp);
			if((pos=tmp.find_first_of(" \t"))!=std::string::npos)
				tmp.erase(pos); // to get rid of whitespace
		}
	}
}

// trouve les differentes stations d'une ligne
std::set<Station*> Plan::stationsDsLigne(std::string ligne)
{
	std::set<Station*> visite;
	Station* act = debLignes[ligne];
	bool ok;
	
	visite.insert(act);
	do {
		ok=false;
		std::vector<Transition> succ = act->getListeSuccesseurs();
		for(std::vector<Transition>::iterator it2=succ.begin();
			 it2!=succ.end() && !ok;it2++)
		{
			if(it2->getLigne()==ligne)
			{	
				if(visite.insert(it2->getDest()).second) // si pas trouve
				{
					act=it2->getDest();
					ok=true;
				}
			}
		}
	}while(ok);
	
	return visite;
} 

std::list<Station*> Plan::dijkstra(Station *s, Station *d) // erreurs d'adressages !!!!
{ // calcule le poid mini pour aller a toutes les stations depuis la station source
	Station *src=s, *dst;
	Transition par;
	std::set<Station*> visited;
	std::list<Station*> path;
	std::vector<Transition> succ;
	double min, couts;
	
	for(map<std::string, Station>::iterator it=graphe.begin();it!=graphe.end();it++)
		it->second.setCoutMin(numeric_limits<double>::infinity());
	s->setPrec(Transition(s, ""));
	s->setCoutMin(0);
	visited.insert(s); // initialisation : on initialise tout les poids a l'infini et on visite le noeud source
	
	do
	{
		min= numeric_limits<double>::infinity();
		for(set<Station*>::iterator it2=visited.begin(); it2!=visited.end();it2++)
		{
			src = (*it2);
			succ = src->getListeSuccesseurs();
			//std::cout << src->getName() << " huhu " << succ.size() 
			//			<< ", " << src->getCoutMin() << " par " << src->getPrec()->getName() <<
			//			std::endl;
			for(std::vector<Transition>::iterator it=succ.begin();it!=succ.end();it++)
			{
				couts = it->getTemps()+src->getCoutMin()+src->getCoutCh(it->getLigne());
				if(couts<min && visited.find(it->getDest())==visited.end())
				{
					min=couts;
					dst=it->getDest();
					par.setDest(src); par.setLigne(it->getLigne());
					//std::cout << " coucou !!! " << dst->getName()<< 
					//" cout " << min << std::endl;
				}
			}
		}
		if(min<numeric_limits<double>::infinity())
		{
			dst->setCoutMin(min);
			dst->setPrec(par);
			visited.insert(dst);
		}
		//std::cout << std::endl;//visited.size() << " huhu " << graphe.size() << std::endl;
	}while(min<numeric_limits<double>::infinity() && dst!=d);//visited.size()<268);//graphe.size());
	
	while(d!=s) 
	{
		path.push_front(d);
		d=d->getPrec().getDest();
	}
	//path.push_front(Transition(s, "")); // ajout source
	return path;
}

void Plan::addAnomLigne(std::string ligne)
{
	std::set<Station*> l = stationsDsLigne(ligne);
	for(std::set<Station*>::iterator it=l.begin();it!=l.end();it++)
	{
		std::vector<Transition> t = (*it)->getListeSuccesseurs();
		for(std::vector<Transition>::iterator it2=t.begin();it2!=t.end();it2++)
			if(it2->getLigne()==ligne)
				it2->setTemps(numeric_limits<double>::infinity()); // mise a l'infini des valeurs
	}
}

void addAnomStation(Station* s)
{
	std::vector<Transition> t = s->getListeSuccesseurs();
	for(std::vector<Transition>::iterator it=t.begin();it!=t.end();it++)
		it->setTemps(numeric_limits<double>::infinity()); // mise a l'infini des valeurs
}
