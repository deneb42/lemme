#include "station.hpp"

Station::Station(string name, string line)
{
    this->nomStation = name;
    this->listeLigne.insert(line);
}
