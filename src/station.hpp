#ifndef __STATION_HPP__
#define __STATION_HPP_

	#include <map>
	#include <string>
	#include "transition.hpp"

	class Station {
		public :
			Station(std::string name);

			void addSuccesseur(Station* stat, std::string ligne); //ajout dune station à la liste des successeurs
			void afficheStation() const; //Affiche les informations de sa station de métro

			std::map<std::string, Transition> getListeSuccesseurs() { return listeSuccesseurs; };
			
			double getCoutMin() const {return coutMin;}
			Station* getPrec() const {return prec;}
			std::string getName() const {return nomStation;}
			void setCoutMin(double p) {coutMin=p;}
			void setPrec(Station* p) {prec=p;}
			
			double coutCh; // gros hack
            double calculerPoidCorrespondance(int age); //calcul le temps pour changer d'un train à l'autre
                                                        //en fonction de l'heure et de l'age du voyageur
		private :
			std::string nomStation;
			std::map<std::string, Transition> listeSuccesseurs; //nom des stations vers lesquelles on peut aller
	
			double coutMin;
			Station* prec;
			
	};
	bool operator==(const Station& s1, const Station& s2);

#endif // __STATION_HPP__
