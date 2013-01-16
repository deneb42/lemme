#ifndef __STATION_HPP__
#define __STATION_HPP_

	#include <set>
	#include <string>
	
	using namespace std; //NECECITE OP DE COMPARAISON

	class Station {
		public :
			Station(string name);//, string line);

			void addSuccesseur(Station* stat, String ligne); //ajout dune station à la liste des successeurs
			//void addLigne(string nom) { listeLignes.insert(nom); }; //ajout d'une nouvelle ligne à la liste des lignes passant par la station.
			void afficheStation(); //Affiche les informations de sa station de métro

			set<Transition> getListeSuccesseurs() { return listeSuccesseurs; };
			//set<string> getListeLigne() { return listeLignes; };
			double getPoid() {return poid;}
			string getName() {return name;}
			void setPoid(double p) {poid=p;}
		private :
			string nomStation;
			set<Transition> listeSuccesseurs; //nom des stations vers lesquelles on peut aller
			//set<string> listeLignes; // liste des lignes qui passent par cette station
			double poid;
			double coutTr; // gros hack
			
	};
	
	boolean operator==(Station& s1, Station& s2);

#endif // __STATION_HPP__
