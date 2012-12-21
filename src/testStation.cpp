#include <iostream>
#include <string>
#include "plan.hpp"
#include "station.hpp"

int main(int argc, char* argv[])
{
    cout << "creation des Stations" << endl;
	Station s1("Etoile", "1");
    Station s2("Porte d'Orleans", "4");
    Station s3("Miromesnil", "10");

    cout << "test afficheStation\n" << endl;
    s1.afficheStation();
    
    cout << "test ajout successeur et ajout ligne\n" << endl;
    s1.addSuccesseur(&s2);
    s1.addLigne("4");
    
    s1.afficheStation();
	
	return 0;
}