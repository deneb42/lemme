
#ifndef __PLAN_HPP__ 
#define __PLAN_HPP__
	
	#include <string>
	#include <map>
	#include <list>
	#include "station.hpp"

	class Plan
	{
		public:
			Plan(std::string path);
			
			std::list<Station*> dijkstra(Station* source, Station *destination);
			std::set<Station*> stationsDsLigne(std::string ligne);
			
			std::map<std::string, Station>* getGraphe() { return &graphe; }
			std::map<std::string, Station*>* getDebLignes() { return &debLignes; }
		private:
			std::map<std::string, Station> graphe;
			std::map<std::string, Station*> debLignes;
	};
	
#endif
