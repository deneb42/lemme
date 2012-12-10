#include <iostream>
#include <fstream>
#include <vector>

#include "lemme.hpp"

using namespace std;

vector<string> SegmenteSelonSymbole(string str, string symbole);
bool valideEtiquette(string s);
void calculOccurences(string nomFichier); 
void ecritureResultat(string nomFichier);


vector<string> categories;
map<string, Lemme> tableLemme;


int main(int argc, char* argv[])
{
	string fichierEntree("../data/est-republicain-2002-TT.txt"),
		   fichierSortie("../data/resultat.txt");
	
	categories.push_back("ADJ");
	categories.push_back("ADV");
	categories.push_back("PRP");
	categories.push_back("NOM");
	categories.push_back("NAM");
	categories.push_back("VER");
	
	calculOccurences(fichierEntree);
	if(tableLemme.size()==0)
	{
		cerr << "pas de Lemmes lu, fin du programme." << endl;
		return 1;
	}
	ecritureResultat(fichierSortie);
	
	return 0;
}

vector<string> SegmenteSelonSymbole(string str, string symbole)
{
	vector<string> res;
	unsigned int olPos=0, pos=string::npos;
	
	do 
	{
		pos=str.find(symbole, olPos);
		
		res.push_back(str.substr(olPos, pos-olPos));
		olPos=pos+1;		
	}while(pos != string::npos && olPos<str.length()); // evite de prendre le retour chariot
	
	return res;
}

bool valideEtiquette(string s)
{
	vector<string>::iterator it;
	for(it=categories.begin();it!=categories.end();it++)
		if(s==(*it))
			return true;
	return false;
}

void calculOccurences(string nomFichier) 
{
	ifstream fichier(nomFichier.c_str());
	string tmp;
	vector<string> segId, segLemme, segInLemme;
	int ligne=1;
	
	if(!fichier.good()) 
	{
		cerr << "Impossible d'ouvrir le ficher " << nomFichier << endl;
		return;
	}
	
	while(!fichier.eof())
	{
		getline(fichier, tmp);
		segId = SegmenteSelonSymbole(tmp, "\t");
		if(segId.size()<3)
		{
			if(!fichier.eof()) // si on n'est pas a la fin du fichier, il y a eu une erreur.
				cerr << "Fichier malforme a la ligne n°" << ligne << endl;
			return;
		}
		segLemme = SegmenteSelonSymbole(segId[2], " ");
		
		for(unsigned int i=0;i< segLemme.size();i++)
		{
			segInLemme = SegmenteSelonSymbole(segLemme[i], "&");
			if(segInLemme.size()<3)
			{
				cerr << "Lemme invalide a la " << ligne << "e ligne" << endl;
				return;
			}
			if(valideEtiquette(segInLemme[1]))
			{
				map<string, Lemme>::iterator it = tableLemme.find(segInLemme[2]);
				
				if(it != tableLemme.end())
				{
					if(it->second.possedeDocID(segId[0]))
						it->second.incrementeOccDansDocID(segId[0]);
					else
						it->second.ajouteDocID(segId[0]);
				}
				else
					tableLemme.insert(pair<string, Lemme>(segInLemme[2], Lemme(segInLemme[2], segId[0])));
			}
		}
		ligne++;
	}
	fichier.close();
}

void ecritureResultat(string nomFichier)
{
	map<string, Lemme>::iterator it;
	ofstream fichier(nomFichier.c_str());
	
	if(fichier.good())
		for(it=tableLemme.begin();it!=tableLemme.end();it++)
			fichier << it->first << "\t" << it->second.getNbDocAyantLemme() << "\t" << it->second.getNbOccTotal() << endl;
	else
		cerr << "Impossible d'ouvrir " << nomFichier << endl;
		
	fichier.close();
}
		
