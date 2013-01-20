
#ifndef __STATION_HPP__
#define __STATION_HPP_

/*!
 * \file station.hpp
 * \brief Classe representant une station
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */

	#include <vector>
	#include <string>
	#include "transition.hpp"

	class Station {
		public :
			Station(std::string name, int age); /*! constructeur d'une station*/

            void addSuccesseur(Station* stat, std::string ligne, std::string heure); /*!<ajout dune station à la liste des successeurs*/
			double calculerPoidCorrespondance(int age); /*!<calcul le temps pour changer d'un train à l'autre
                                                         * en fonction de l'heure et de l'age du voyageur*/
			
			std::string stringStationParParcours() const; /*!< Format special pour afficher le parcours correctement.*/
            std::string toString() const; /*!<Retourne une chaine de caracteres contenant les informations de la station*/
            std::vector<Transition>* getListeSuccesseurs() { return &listeSuccesseurs; }; /*!<Getter de la liste des successeurs de la station*/
            double getCoutMin() const {return coutMin;} /*!<Getter de le coutMin, cout minimum renvoye par dijkstra*/
			double getCoutCh(std::string ligne); /*!<Getter sur coutCh, cout du changement de ligne dans la station*/
			Transition getPrec() const {return prec;} /*!<Getter surPrec, transition qui mene à la station precedente par dijkstra*/
			std::string getName() const {return nomStation;} /*!<Getter sur le nom de la station*/
			void setCoutMin(double p) {coutMin=p;} /*!<Setter sur coutMin*/
			void setPrec(Transition p) {prec=p;} /*!<Setter sur Prec*/
			void setHeure(std::string h); /*!< Recalcule les temps de changement en fonction de la nouvelle heure */
		private :
			std::string nomStation; /*!<Nom de la station*/
			std::vector<Transition> listeSuccesseurs; /*!<Nom des stations vers lesquelles on peut aller*/
            
            int ageVoyageur; /*!< age du Voyageur, genere a l'appel du constructeur du plan*/
			double coutCh; /*!<cout du changement de ligne dans la station (correspondance)*/
			double coutMin; /*!<cout minimum renvoye par dijkstra pour venir à la station*/
			Transition prec; /*!<transition qui mene à la station precedente par dijkstra*/

			
	};
	bool operator==(const Station& s1, const Station& s2); /*!<Surcharge de l'operateur == */

#endif // __STATION_HPP__
