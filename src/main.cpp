#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "lemme.hpp"

using namespace std;

void lireFichier(string path);

int main(int argc, char* argv[])
{
	//=====================
	//Jean
	//=====================
	
	vector<string> categories("adjectif", "adverbe", "preposition", "nom commun", "nom propre", "verbe");	//conteneur des différentes catégories.
	
	//=====================
	//fin Jean
	//=====================	
	std::cout << "Hello world !" << std::endl;
	
	lireFichier("../data/est-republicain-2002-TT.txt");
	
	return 0;
}

void lireFichier(string path) 
{
	ifstream fichier(path.c_str());
	string tmp;
	vector<string> v;
	unsigned int pos=0, pos2=0, indexChar=0;
	char caracteres[] = "&& "; 
	
	if(!fichier.good()) 
	{
		cerr << "Impossible d'ouvrir le ficher " << path << endl;
		exit(1);
	}
	
	//while(!fichier.eof())
	{
		getline(fichier, tmp);
		pos2 = tmp.find('\t', pos);
		//cout << "pos : " << pos << " pos2 : " << pos2 << endl;
		if(pos2!=string::npos)
		{
			v.push_back(tmp.substr(pos, pos2-pos));
			pos=pos2+1;
		} // ID1
		
		pos2 = tmp.find('\t', pos);
		//cout << "pos : " << pos << " pos2 : " << pos2 << endl;
		if(pos2!=string::npos)
		{
			v.push_back(tmp.substr(pos, pos2-pos));
			pos=pos2+1;
		} //ID2
		
		while( (pos2 = tmp.find(caracteres[indexChar], pos)) != string::npos)
		{
			cout << "pos : " << pos << " pos2 : " << pos2 << endl;
			v.push_back(tmp.substr(pos, pos2-pos));
			pos=pos2+1;
			indexChar = (indexChar+1)%3;
			// Mot / etiquette/lemme
		}
		v.push_back(tmp.substr(pos)); // last word
		
		for(unsigned int i=0;i<v.size();i++)
			cout << v[i] << endl;
	}
	
}
