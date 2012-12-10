
#include <iostream>
#include <map>

#include "lemme.hpp"

Lemme::Lemme(string lemme, string docID)
{
	this->lemme = lemme;
	this->nbDocAyantLemme = 1;
	this->tableOcc.insert( pair<string, int>(docID, 1));
}

int Lemme::getNbOccTotal() const // Renvoie le nombre d'occurrences du lemme dans le corpus
{
	map<string, int>::const_iterator it;
	int temp=0;

	for(it = tableOcc.begin(); it!=tableOcc.end(); ++it)
		temp += it->second;	//on additionne l'ensemble des occurences du lemme.
		
	return temp;
}

bool Lemme::possedeDocID(string docID) const // Renvoie si le tableau associatif contient déjà cet identifiant de document.  
{
	return (tableOcc.find(docID)!=tableOcc.end());
}

void Lemme::ajouteDocID(string docID) // Ajoute un identifiant de document au tableau associatif.
{
	if(!possedeDocID(docID))
	{
		this->tableOcc.insert( pair<string, int>(docID, 1));
		nbDocAyantLemme++;
	}
	else
		std::cerr << "on ne devrait pas passer ici..." << std::endl;
		
}

void Lemme::incrementeOccDansDocID(string docID) // Incrémente le nombre d'occurrences du lemme pour cet identifiant de document.
{
	if(possedeDocID(docID))
		tableOcc[docID]++;		
	else
		std::cerr << "on ne devrait pas passer ici..." << std::endl;
}

