#include "lemme.hpp"

Lemme::Lemme(string lemme, string docID)
{
	this->lemme = lemme;
	this->nbDocAyantLemme = 0;
}	

int Lemme::getNbOccDansDocID(string docID) const // Renvoie le nombre d'occurrences du lemme dans le document identifié par docID.
{
  
}

int Lemme::getNbOccTotal() const // Renvoie le nombre d'occurrences du lemme dans le corpus
{

}

bool Lemme::possedeDocID(string docID) const // Renvoie si le tableau associatif contient déjà cet identifiant de document.  
{

}

void Lemme::ajouteDocID(string docID) // Ajoute un identifiant de document au tableau associatif.
{

}

void Lemme::incrementeOccDansDocID(string docID) // Incrémente le nombre d'occurrences du lemme pour cet identifiant de document.
{

}
