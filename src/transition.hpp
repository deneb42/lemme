
#ifndef __TRANTISION_HPP__ 
#define __TRANSITION_HPP__
	
	#include <string>
	
	class Station;
	

	class Transition
	{
		public:
			Transition(Station* d, std::string l):dest(d),ligne(l) {}
			
            double calculerPoidsVoyageurs(int nbPersonnes);
            void calculerPoidsTransition(int heure);
			void setDest(Station* d) { dest = d; }
			void setLigne(std::string l) { ligne = l; }
			Station* getDest() const { return dest; }
			std::string getLigne() const { return ligne; }
			double getTemps() const { return temps; }
		private:
			Station* dest;
			std::string ligne;
			double temps;
	};
	
#endif
