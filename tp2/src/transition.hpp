
#ifndef __TRANTISION_HPP__ 
#define __TRANSITION_HPP__
	
/*!
 * \file Transition.hpp
 * \brief Classe representant une transition entre deux stations
 * \author {Jean BADIE, Benjamin BLOIS}
 * \date 17 janvier 2013
 */	
	
	#include <string>
	#include <cstdlib>
	
	class Station; // forward declaration necessaire pour utiliser Station (sans causer de deadlock d'inclusion)
	

	class Transition
	{
		public:
            Transition() {dest=NULL; } /*!<Constructeur par defaut*/
			Transition(Station* d, std::string l):dest(d),ligne(l) {} /*!<Constructeur de Transition*/

            double calculerPoidsVoyageurs(int nbPersonnes); /*!<Calcul le poids des voyageurs en fonction de l'heure, appele pendant la
                                                             * creation du graphe*/
            void calculerPoidsTransition(std::string heure); /*!<Calcul le poids des transition en fonction de l'heure, appele pendant la
															  * creation du graphe*/
			
			Station* getDest() const { return dest; } /*!<Getter sur destination*/
			std::string getLigne() const { return ligne; } /*!<Getter sur ligne*/
			double getTemps() const { return temps; } /*!<Getter sur temps*/
			void setDest(Station* d) { dest = d; } /*!<Setter sur destination*/
			void setLigne(std::string l) { ligne = l; } /*!<Setter sur ligne*/
			void setTemps(double t) { temps = t; } /*!<Setter sur temps*/
		private:
			Station* dest; /*!<Station de destination*/
			std::string ligne; /*!<Ligne entre les deux stations*/
			double temps; /*!<temps du trajet entre les deux stations*/
	};
	
#endif // __TRANSITION_HPP__
