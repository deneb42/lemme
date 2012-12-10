#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "lemme.hpp"

using namespace std;

vector<string> categories;
map<string, Lemme> tableLemme;

vector<string> SegmenteSelonSymbole(string str, string symbole);
bool valideEtiquette(string s);
void calculOccurences(string nomFichier); 

int main(int argc, char* argv[])
{
	string nomFichier("../data/est-republicain-2002-TT.txt");
	
	categories.push_back("ADJ");
	categories.push_back("ADV");
	categories.push_back("PRP");
	categories.push_back("NOM");
	categories.push_back("NAM");
	categories.push_back("VER");
	
	
	calculOccurences(nomFichier);
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
		exit(1);
	}
	
	//while(!fichier.eof())
	{
		getline(fichier, tmp);
		segId = SegmenteSelonSymbole(tmp, "\t");
		if(segId.size()<3)
		{
			cerr << "Fichier malforme a la ligne n°" << ligne << endl;
			exit(1);
		}
		segLemme = SegmenteSelonSymbole(segId[2], " ");
		
		for(unsigned int i=0;i< segLemme.size();i++)
		{
			segInLemme = SegmenteSelonSymbole(segLemme[i], "&");
			if(segInLemme.size()<3)
			{
				cerr << "Lemme invalide a la " << ligne << "e ligne" << endl;
				exit(1);
			}
			if(valideEtiquette(segInLemme[1]))
			{
				cout << segInLemme[0] << " " << segInLemme[1] << " " << segInLemme[2] << endl;
			}
		}
		ligne++;
	}
	
	fichier.close();
}
