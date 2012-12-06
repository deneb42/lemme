#include <map>

#include "lemme.hpp"
#include <map>

Lemme::Lemme(string lemme, string docID)
{
	this->lemme = lemme;
	this->nbDocAyantLemme = 0;
	this->tableOcc.insert( pair<string, int>(docID, 0));
}	


int Lemme::getNbOccTotal() const // Renvoie le nombre d'occurrences du lemme dans le corpus
{

	map<string, int> :: const_iterator it = tableOcc.begin();

	int temp;		//valeur a retourner

	for(it = tableOcc.begin(); it!=tableOcc.end(); ++it)
	{
		temp += (*it).second;	//on additionne l'ensemble des occurences du lemme.
	}
	return temp;
}

bool Lemme::possedeDocID(string docID) const // Renvoie si le tableau associatif contient déjà cet identifiant de document.  
{
	if(tableOcc.count(docID) == 0)
		return true;
	else return false;
}

void Lemme::ajouteDocID(string docID) // Ajoute un identifiant de document au tableau associatif.
{
	if(tableOcc.count(docID) == 0)
	{
		this->tableOcc.insert( pair<string, int>(docID, 0));
		nbDocAyantLemme += 1;
	}
		
}

void Lemme::incrementeOccDansDocID(string docID) // Incrémente le nombre d'occurrences du lemme pour cet identifiant de document.
{
	if(tableOcc.count(docID) == 0)
	{
		ajouteDocID(docID);
	}

	else if(tableOcc.count(docID)==1)
	{
		tableOcc[docID] += 1; // a tester
	}	
}
