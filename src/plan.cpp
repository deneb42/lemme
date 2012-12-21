
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "plan.hpp"

using namespace std;

Plan::Plan(string path) 
{
	ifstream ifs(path.c_str());
	string tmp, ligne;
	
	if(!ifs.good()) {
		cerr << "erreur a l'ouverture du fichier" << endl;
		exit(1);
	}
	while(!ifs.eof())
	{
		getline(ifs, ligne);
		cout << "ligne " << ligne << endl; // traitement pour garder le nom de la ligne
		getline(ifs, tmp);
		while(!tmp.empty())
		{
			cout << "ajout de la station " << tmp << " a la ligne " << ligne << endl;
			getline(ifs, tmp);
		}
	}
}
