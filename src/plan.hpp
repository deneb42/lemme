
#ifndef __PLAN_HPP__ 
#define __PLAN_HPP__
	
	#include <string>
	#include <map>
	#include "station.hpp"

	class Plan
	{
		public:
			Plan(std::string path);
			
			void dijkstra(Station* source);
			
			std::map<std::string, Station>* getGraphe() { return &graphe; }
		private:
			std::map<std::string, Station> graphe;
	};
	
#endif
