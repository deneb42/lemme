
#ifndef __STATION_HPP__
#define __STATION_HPP_

	#include <vector>
	#include <string>
	#include "transition.hpp"

/*!
 * \file station.hpp
 * \brief Classe representant une station
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */

	class Station {
		public :
        Station(std::string name, int age);

            void addSuccesseur(Station* stat, std::string ligne, std::string heure); /*!<ajout dune station à la liste des successeurs*/
			std::string toString() const; /*!<Retourne une chaine de caracteres contenant les informations de la station*/
            void afficheStationParParcours() const; /*!< Format special pour afficher le parcours correctement.*/

			std::vector<Transition>* getListeSuccesseurs() { return &listeSuccesseurs; }; /*!<Getter de la liste des successeurs de la station*/
			
            double getCoutMin() const {return coutMin;} /*!<Getter de le coutMin, cout minimum renvoye par dijkstra*/
			double getCoutCh(std::string ligne); /*!<Getter sur coutCh, cout du changement de ligne dans la station*/
			Transition getPrec() const {return prec;} /*!<Getter surPrec, transition qui mene à la station precedente par dijkstra*/
			std::string getName() const {return nomStation;} /*!<Getter sur le nom de la station*/
			void setCoutMin(double p) {coutMin=p;} /*!<Setter sur coutMin*/
			void setPrec(Transition p) {prec=p;} /*!<Setter sur Prec*/
			
            double calculerPoidCorrespondance(int age); /*!<calcul le temps pour changer d'un train à l'autre
                                                        en fonction de l'heure et de l'age du voyageur*/
		private :
            double coutCh; /*!<cout du changement de ligne dans la station (correspondance)*/
			std::string nomStation; /*!<Nom de la station*/
			std::vector<Transition> listeSuccesseurs; /*!<Nom des stations vers lesquelles on peut aller*/
            
            int ageVoyageur; /*!< age du Voyageur, genere a l'appel du constructeur du plan*/
			double coutMin; /*!<cout minimum renvoye par dijkstra pour venir à la station*/
			Transition prec; /*!<transition qui mene à la station precedente par dijkstra*/

			
	};
	bool operator==(const Station& s1, const Station& s2); /*!<Surcharge de l'operateur == */

#endif // __STATION_HPP__
