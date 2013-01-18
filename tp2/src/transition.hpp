
#ifndef __TRANTISION_HPP__ 
#define __TRANSITION_HPP__
	
	#include <string>

/*!
 * \file Transition.hpp
 * \brief Classe representant une transition entre deux stations
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */


	class Station;
	

	class Transition
	{
		public:
            Transition() {} /*!<Constructeur vide*/
			Transition(Station* d, std::string l):dest(d),ligne(l) {} /*!<Constructeur*/
			
            double calculerPoidsVoyageurs(int nbPersonnes); /*!<Calcul le poids des voyageurs en fonction de l'heure, appele pendant la
                                                                creation du graphe*/
        void calculerPoidsTransition(std::string heure); /*!<Calcul le poids des transition en fonction de l'heure, appele pendant la
                                                          creation du graphe*/
			void setDest(Station* d) { dest = d; } /*!<Setter sur Destination*/
			void setLigne(std::string l) { ligne = l; } /*!<Setter sur ligne*/
			Station* getDest() const { return dest; } /*!<Getter sur Dest*/
			std::string getLigne() const { return ligne; } /*!<Getter sur Ligne*/
			double getTemps() const { return temps; } /*!<Getter sur Temps*/
		private:
			Station* dest; /*!<Station de destination*/
			std::string ligne; /*!<Ligne entre les deux stations*/
			double temps; /*!<temps du trajet entre les deux stations*/
	};
	
#endif
