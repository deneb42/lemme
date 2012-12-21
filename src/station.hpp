#ifndef __STATION_HPP__
#define __STATION_HPP_

	#include <map>
	#include <string>
	
	using namespace std;

	class Station {
		private :
			string nomStation;
			set<*Station> listeSuccesseurs; //nom des stations vers lesquelles on peut aller
			set<string> listeLignes; // liste des lignes qui passent par cette station

		public :
			Station(string name, string line);
			
			void addSuccesseur(*Station stat) { listeSuccesseurs.insert(stat); }; //ajout dune station à la liste des successeurs
            void addlisteLignes(string nom) { listeLignes.insert(nom); }; //ajout d'une nouvelle ligne à la liste des lignes passant par la station.
            void afficheStation(); //Affiche les informations de sa station de métro
        
            set<&Station> getlisteSuccesseurs() { return listeSuccesseurs; };
            set<string> getlisteLigne() { return listeLignes; };
			
	};

#endif // __STATION_HPP__
