#include "lemme.hpp"

Lemme::Lemme(string lemme, string docID)
{
	this->lemme = lemme;
	this->nbDocAyantLemme = 0;
	this->tableOc.inster( pair<string, int>(docID, 0));
}	


int Lemme::getNbOccTotal() const // Renvoie le nombre d'occurrences du lemme dans le corpus
{
	map<string, int> :: iterator it;
	int temp;		//valeur a retourner
	for(it = tableOc.begin(); it!=tableOc.end(); ++it)
	{
		temp += (*it).second;	//on aditionne l'ensemble des occurences du lemme.
	}
}

bool Lemme::possedeDocID(string docID) const // Renvoie si le tableau associatif contient déjà cet identifiant de document.  
{
	if(tableOC.count(docID) == 0)
		return true;
	else return false;
}

void Lemme::ajouteDocID(string docID) // Ajoute un identifiant de document au tableau associatif.
{
	if(tableOC.count(docID) == 0)
	{
		this->tableOc.inster( pair<string, int>(docID, 0));
		nbDocAyantLemme += 1;
	}
		
}

void Lemme::incrementeOccDansDocID(string docID) // Incrémente le nombre d'occurrences du lemme pour cet identifiant de document.
{
	if(tableOC.count(docID) == 0)
	{
		ajouteDocID(docID);
	}
	else if(tableOC.count(docID)) == 1
	{
		tableOC[docID] += 1; // a tester
	}	
}
