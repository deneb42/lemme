
#ifndef __TRANTISION_HPP__ 
#define __TRANSITION_HPP__
	
	#include <string>
	#include <set>
	#include "station.hpp"
	
	using namespace std;

	class Transition
	{
		public:
			Transition(Station& d, string l):dest(d), ligne(l);
			
		private:
			Station* dest;
			string ligne;
	};
	
#endif
