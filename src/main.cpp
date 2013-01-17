
#include <iostream>
#include <string>
#include <set>
#include "plan.hpp"

int main()//int argc, char* argv[])
{
	int i=10;
	
	Plan p("../data/metro.txt");
	
	for(std::map<std::string, Station>::iterator it=p.getGraphe()->begin();it!=p.getGraphe()->end() && i>0;it++)
	{
		it->second.afficheStation();
		//i--;
	}
	
	return 0;
}
