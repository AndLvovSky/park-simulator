#ifndef PARK_INTERFACE_H
#define PARK_INTERFACE_H

#include "park.h"
#include <iostream>

using namespace std;

enum TreeException {
	AGE_OUT_OF_RANGE,
	COORDINATES_OUT_OF_RANGE
};

class ParkInterface {
	
	private:
		
		const string defaultDataBaseName = "parkDataBase.dat";
		String defaultSpecies;
		Age defaultAge;
		Coordinates defaultLocation;
		
		string dataBaseName;
		Park park;
		
		void printMainMenu();
		void plantNewInterface();
		void addWithAgeInterface();
		void addInterface();
		void cutBySpeciesInterface();
		void cutByAgeInterface();
		void cutByLocationInterface();
		void cutInterface();
		void findAverageAgeBySpeciesInterface();
	
	public:
	
		ParkInterface();
		ParkInterface(string fileName);
		void run();
};

#endif // PARK_INTERFACE_H
