#ifndef __STATION_HPP__
#define __STATION_HPP_

	#include <set>
	#include <string>
	#include "transition.hpp"
	
	using namespace std;

	class Station {
		public :
			Station(string name);//, string line);

			void addSuccesseur(const Station* stat, string ligne); //ajout dune station à la liste des successeurs
			//void addLigne(string nom) { listeLignes.insert(nom); }; //ajout d'une nouvelle ligne à la liste des lignes passant par la station.
			void afficheStation() const; //Affiche les informations de sa station de métro
            double calculerPoidCorrespondance(int age); //calcul le temps pour changer d'un train à l'autre
                                                        //en fonction de l'heure et de l'age du voyageur
			set<Transition> getListeSuccesseurs() { return listeSuccesseurs; };
			//set<string> getListeLigne() { return listeLignes; };
			double getPoid() const {return poid;}
			string getName() const {return nomStation;}
			void setPoid(double p) {poid=p;}
		private :
			string nomStation;
			set<Transition> listeSuccesseurs; //nom des stations vers lesquelles on peut aller
			//set<string> listeLignes; // liste des lignes qui passent par cette station
			double poid;
			double coutTr; // gros hack
			
	};
	
	bool operator==(const Station& s1, const Station& s2);
	bool operator<(const Station& s1, const Station& s2); // pour le set

#endif // __STATION_HPP__
