#ifndef __STATION_HPP__
#define __STATION_HPP_

	#include <vector>
	#include <string>
	#include "transition.hpp"

	class Station {
		public :
        Station(std::string name, int age);

            void addSuccesseur(Station* stat, std::string ligne, std::string heure); //ajout dune station à la liste des successeurs
			void afficheStation() const; //Affiche les informations de sa station de métro
        void afficheStationParParcours() const; // Format special pour afficher le parcours correctement.

			std::vector<Transition>& getListeSuccesseurs() { return listeSuccesseurs; };
			
			double getCoutMin() const {return coutMin;}
			double getCoutCh(std::string ligne);
			Transition getPrec() const {return prec;}
			std::string getName() const {return nomStation;}
			void setCoutMin(double p) {coutMin=p;}
			void setPrec(Transition p) {prec=p;}
			
			double coutCh;
            double calculerPoidCorrespondance(int age); //calcul le temps pour changer d'un train à l'autre
                                                        //en fonction de l'heure et de l'age du voyageur
		private :
			std::string nomStation;
			std::vector<Transition> listeSuccesseurs; //nom des stations vers lesquelles on peut aller
            
            int ageVoyageur;
			double coutMin;
			Transition prec;
			//Station* prec;
			
	};
	bool operator==(const Station& s1, const Station& s2);

#endif // __STATION_HPP__
