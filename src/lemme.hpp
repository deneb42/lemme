#ifndef LEMME_H
#define LEMME_H

	#include <map>
	#include <string>

	using namespace std;

	class Lemme {
		private :
			string lemme; // Le lemme
			int nbDocAyantLemme; // Nombre de documents possédant ce lemme
			map<string, int> tableOcc; // Tableau associatif pour les occurrences par documentID (clé) et nombre d'occurences du lemme dans ce document (valeur)

		public :
			Lemme(string lemme, string docID);

			string getLemme() const; // Renvoie le lemme.
			int getNbDocAyantLemme() const; // Renvoie le nombre d'identifiants de documents possédant ce lemme.
			int getNbOccDansDocID(string docID) const; // Renvoie le nombre d'occurrences du lemme dans le document identifié par docID.
			int getNbOccTotal() const; // Renvoie le nombre d'occurrences du lemme dans le corpus
			bool possedeDocID(string docID) const; // Renvoie si le tableau associatif contient déjà cet identifiant de document.  

			void ajouteDocID(string docID); // Ajoute un identifiant de document au tableau associatif.
			void incrementeOccDansDocID(string docID); // Incrémente le nombre d'occurrences du lemme pour cet identifiant de document.
	};

#endif // LEMME_H
