
#ifndef __PLAN_HPP__ 
#define __PLAN_HPP__
	
	#include <string>
	#include <set>
	#include "station.hpp"
	
	using namespace std;

	class Plan
	{
		public:
			Plan(string path);
			
			void dijkstra(Station &source);
			
		//private:
			set<Station> graphe;
	};
	
#endif
