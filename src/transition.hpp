
#ifndef __TRANTISION_HPP__ 
#define __TRANSITION_HPP__
	
	#include <string>
	#include <set>
	#include "station.hpp"
	
	using namespace std;

	class Transition
	{
		public:
			Transition(Station* d, string l):dest(d),ligne(l) {}
			
			
			void setDest(Station* d) { dest = d; }
			void setLigne(string l) { ligne = l; }
			Station* getDest() { return dest; }
			string getLigne() { return ligne; }
		
		private:
			Station* dest;
			string ligne;
	};
	
#endif
