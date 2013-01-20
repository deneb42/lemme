
/*!
 * \file plan.cpp
 * \brief Classe representant l'ensemble du reseau
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 *
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <set>
#include <list>
#include <random>

#include "plan.hpp"


/*!
 * \fn Plan
 * \param path, heure, anomalie
 */
Plan::Plan(std::string path, std::string heure)
{
	std::ifstream ifs(path.c_str());
	std::string tmp, ligne;
	std::random_device rd;
	int pos, age;
	
    // GENERATION DE L'AGE DU VOYAGEUR
    age = 7 + rd()*10000%80; // un voyageur a de 7 a 87 ans.
    std::cout << "age : " << age << std::endl;
	
	if(!ifs.good()) {
		std::cerr << "erreur a l'ouverture du fichier" << std::endl;
		exit(1);
	}
	
	while(!ifs.eof())
	{
		std::map<std::string, Station>::iterator act, prec;
		
		getline(ifs, ligne);
		if((pos=ligne.find_first_of(" \t"))!=std::string::npos)
			ligne.erase(pos); // to get rid of whitespace
		
		getline(ifs, tmp);
		if((pos=tmp.find_first_of(" \t"))!=std::string::npos)
			tmp.erase(pos); // to get rid of whitespace
		prec=graphe.insert(std::pair<std::string, Station>(tmp, Station(tmp, age))).first; // traitement particulier pour le premier elem, le cast automatique fait appel au constructeur
		debLignes.insert(std::pair<std::string, Station*>(ligne, &(prec->second)));
		
		getline(ifs, tmp);
		if((pos=tmp.find_first_of(" \t"))!=std::string::npos)
			tmp.erase(pos); // to get rid of whitespace
		while(!tmp.empty())
		{
			act=graphe.insert(std::pair<std::string, Station>(tmp, Station(tmp, age))).first; // ajout de l'element, s'il est deja present, l'elem existant est retourne
			act->second.addSuccesseur(&(prec->second), ligne, heure);
			prec->second.addSuccesseur(&(act->second), ligne, heure); // on ajoute les liaisons
			prec = act;
			getline(ifs, tmp);
			if((pos=tmp.find_first_of(" \t"))!=std::string::npos)
				tmp.erase(pos); // to get rid of whitespace
		}
	}
}

/**
 * \fn dijkstra
 * \param Station, Station
 * \return list<Station>
 */
std::list<Station*> Plan::dijkstra(Station *s, Station *d) throw(int)
{ // version maison, possibilite de faire quelques quelques ameliorations notables
	Station *src=s, *dst;
	Transition par;
	std::set<Station*> visited;
	std::list<Station*> path;
	double min, couts;
	
	for(std::map<std::string, Station>::iterator it=graphe.begin();it!=graphe.end();it++)
		it->second.setCoutMin(std::numeric_limits<double>::infinity());
	s->setPrec(Transition());
	s->setCoutMin(0);
	visited.insert(s); // initialisation : on initialise tout les poids a l'infini et on visite le noeud source
	
	do
	{
		min= std::numeric_limits<double>::infinity();
		for(std::set<Station*>::iterator it2=visited.begin(); it2!=visited.end();it2++)
		{
			src = (*it2);
			for(std::vector<Transition>::iterator it=src->getListeSuccesseurs()->begin();it!=src->getListeSuccesseurs()->end();it++)
			{
				couts = it->getTemps()+src->getCoutMin()+src->getCoutCh(it->getLigne());
				if(couts<min && visited.find(it->getDest())==visited.end())
				{
					min=couts;
					dst=it->getDest();
					par.setDest(src); par.setLigne(it->getLigne());
				}
			}
		}
		if(min<std::numeric_limits<double>::infinity())
		{
			dst->setCoutMin(min);
			dst->setPrec(par);
			visited.insert(dst);
		}
	}while(min<std::numeric_limits<double>::infinity() && dst!=d);

	while(d!=s && d!= NULL) // une fois qu'on a les poids min vers tout les noeuds, on pars de la destination et on remonte la piste
	{
		path.push_front(d);
		d=d->getPrec().getDest();
	}
	
	if(d==NULL) // si on est pas a la source, le chemin n'est pas possible
		throw 0;
	
	return path;
}

/**
 * \fn StationsDsLigne
 * \param ligne
 * \return set<Station>
 */
std::set<Station*> Plan::stationsDsLigne(std::string ligne)
{ // trouve les differentes stations d'une ligne
	std::set<Station*> visite;
	Station* act = debLignes[ligne];
	bool ok;
	
	visite.insert(act);
	do {
		ok=false;
		for(std::vector<Transition>::iterator it2=act->getListeSuccesseurs()->begin();
			 it2!=act->getListeSuccesseurs()->end() && !ok;it2++)
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

/**
 * \fn addAnomLigne
 * \param ligne
 */
void Plan::addAnomLigne(std::string ligne)
{
	std::set<Station*> l = stationsDsLigne(ligne);
	for(std::set<Station*>::iterator it=l.begin();it!=l.end();it++)
	{
		for(std::vector<Transition>::iterator it2=(*it)->getListeSuccesseurs()->begin();it2!=(*it)->getListeSuccesseurs()->end();it2++)
			if(it2->getLigne()==ligne)
				it2->setTemps(std::numeric_limits<double>::infinity()); // mise a l'infini des valeurs
	}
}

/**
 * \fn addAnomStation
 * \param Station
 */
void Plan::addAnomStation(Station* s)
{
	for(std::vector<Transition>::iterator it=s->getListeSuccesseurs()->begin();it!=s->getListeSuccesseurs()->end();it++)
		it->setTemps(std::numeric_limits<double>::infinity()); // mise a l'infini des valeurs
}

/**
 * \fn toString
 */
std::string Plan::toString()
{
	std::string str("");
	for(std::map<std::string, Station>::iterator it=graphe.begin();it!=graphe.end();it++)
		str+= it->second.toString();
	return str;
}

/**
 * \fn setHeure
 */
void Plan::setHeure(std::string h)
{
	heure = h;
	for(std::map<std::string, Station>::iterator it=graphe.begin();it!=graphe.end();it++)
		it->second.setHeure(h);
}
