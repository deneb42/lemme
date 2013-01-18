
#ifndef __PLAN_HPP__ 
#define __PLAN_HPP__

/*!
 * \file plan.hpp
 * \brief Classe representant l'ensemble du reseau
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */
	
	#include <string>
	#include <map>
	#include <list>
	#include "station.hpp"

	class Plan
	{
		public:
            Plan(std::string path, std::string heure, bool anomalie);/*!< Conctructeur du plan*/
			
			std::list<Station*> dijkstra(Station* source, Station *destination);/*!<Algoritme de Dijkstra*/
			std::set<Station*> stationsDsLigne(std::string ligne);/*!<Retourne la liste des stations d'une meme ligne*/
			
			std::map<std::string, Station>* getGraphe() { return &graphe; } /*!<Getter sur le graphe cree*/
			std::map<std::string, Station*>* getDebLignes() { return &debLignes; }/*!<Getter sur l'ensemble des terminus*/
		private:
			std::map<std::string, Station> graphe; /*!<graphe representant le reseau*/
			std::map<std::string, Station*> debLignes;/*!<ensemble des terminus*/
	};
	
#endif
