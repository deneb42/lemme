
#ifndef __TRANTISION_HPP__ 
#define __TRANSITION_HPP__
	
	#include <string>
	#include <set>
	
	class Station;
	
	using namespace std;

	class Transition
	{
		public:
			Transition(const Station* d, string l):dest(d),ligne(l) {}
			
			
			void setDest(const Station* d) { dest = d; }
			void setLigne(string l) { ligne = l; }
			const Station* getDest() const { return dest; }
			string getLigne() const { return ligne; }
		
		private:
			const Station* dest;
			string ligne;
	};
	
	bool operator<(const Transition& t1, const Transition& t2);
	
#endif
