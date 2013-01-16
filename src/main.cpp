
#include <iostream>
#include <string>
#include <set>
#include "plan.hpp"

int main()//int argc, char* argv[])
{
	int i=10;
	
	Plan p("../data/metro.txt");
	
	for(std::set<Station>::iterator it=p.graphe.begin();it!=p.graphe.end() && i>0;it++)
	{
		it->afficheStation();
		i--;
	}
	
	return 0;
}
