#include "park_interface.h"
#include <iostream>
#include <conio.h>

using namespace std;

ParkInterface :: ParkInterface() {
	dataBaseName = defaultDataBaseName;
} 

ParkInterface :: ParkInterface(string fileName) {
	dataBaseName = fileName;
	park.readFromBinaryFile(dataBaseName.c_str());
}

void ParkInterface :: printMainMenu() {
	cout << "Choose an operation and press accoding number" << endl;
	cout << "//--------------------------------------------//" << endl;
	cout << "  1 - add a tree" << endl;
	cout << "  2 - cut trees by filter" << endl;
	cout << "  3 - find average age by species" << endl; 
	cout << "  4 - show park" << endl;
	cout << "  5 - exit" << endl;
	cout << "//--------------------------------------------//" << endl;
	cout << "current operation = ";
}

void ParkInterface :: plantNewInterface() {
	String species;
	Coordinates location;
	cout << "Print species: ";
	species.read();
	try {
		cout << "Print X coordinate: ";
		cin >> location.x;
		if (!cin.good() || location.x < 0) {
			throw COORDINATES_OUT_OF_RANGE;
		}
		cout << "Print Y coordinate: ";
		cin >> location.y;
		if (!cin.good() || location.y < 0) {
			throw COORDINATES_OUT_OF_RANGE;
		}
	} catch (TreeException ex) {
		cout << "Incorrect coordinates!" << endl << endl;  
		return;
	}
	Tree tree(species, time(NULL), location);
	park.addTree(tree);
	cout << endl;
}

void ParkInterface :: addWithAgeInterface() {
	String species;
	Age age;
	Coordinates location;
	cout << "Print species: ";
	species.read();
	try {
		cout << "Print tree's years: ";
		cin >> age.years;
		if (!cin.good() || age.years < 0) {
			throw AGE_OUT_OF_RANGE;
		}
		cout << "Print tree's months: ";
		cin >> age.months;
		if (!cin.good() || age.months < 0 || age.months > 12) {
			throw AGE_OUT_OF_RANGE;
		}
		cout << "Print X coordinate: ";
		cin >> location.x;
		if (!cin.good() || location.x < 0) {
			throw COORDINATES_OUT_OF_RANGE;
		}
		cout << "Print Y coordinate: ";
		cin >> location.y;
		if (!cin.good() || location.y < 0) {
			throw COORDINATES_OUT_OF_RANGE;
		}
	} catch (TreeException ex) {
		switch (ex) {
			case AGE_OUT_OF_RANGE         : cout << "Incorrect age!" << endl << endl;         return;
			case COORDINATES_OUT_OF_RANGE :	cout << "Incorrect coordinates!" << endl << endl; return; 
		}
	}
	Tree tree(species, getPlantTime(age), location);
	park.addTree(tree);
	cout << endl;
}

void ParkInterface :: addInterface() {
	cout << "If you want to plant a new tree press 1," << endl;
	cout << "else if you want to add a tree with certain age press 2" << endl;
	int curOperation = getche() - 48;
	cout << endl;
	if (curOperation == 1) {
		plantNewInterface();
	} else if (curOperation == 2) {
		addWithAgeInterface();
	}
}

void ParkInterface :: cutBySpeciesInterface() {
	cout << "Print species you want to cut: ";
	String species;
	species.read();
	park.cutByFilter(SPECIES, species, defaultAge, defaultLocation);
}

void ParkInterface :: cutByAgeInterface() {
	cout << "Choose a comparator and press acording key" << endl;
	cout << "//--------------------------------------------//" << endl;
	cout << "  1 - equal" << endl;
	cout << "  2 - greater" << endl;
	cout << "  3 - less" << endl;
	cout << "//--------------------------------------------//" << endl;
	int curOperation = getche() - 48;
	cout << endl;
	Age age;
	try {
		cout << "Print tree's years: ";
		cin >> age.years;
		if (!cin.good() || age.years < 0) {
			throw AGE_OUT_OF_RANGE;
		}
		cout << "Print tree's months: ";
		cin >> age.months;
		if (!cin.good() || age.months < 0 || age.months > 12) {
			throw AGE_OUT_OF_RANGE;
		}
	} catch (TreeException ex) {
		cout << "Incorrect age!" << endl << endl; return;
	}
	switch (curOperation) {
		case 1  : park.cutByFilter(AGE, defaultSpecies, age, defaultLocation, EQUAL);   break;
		case 2  : park.cutByFilter(AGE, defaultSpecies, age, defaultLocation, GREATER); break;
		case 3  : park.cutByFilter(AGE, defaultSpecies, age, defaultLocation, LESS);    break;
		default : 									                                    break;
	}
	cout << endl;
}

void ParkInterface :: cutByLocationInterface() {
	Coordinates location;
	try {
		cout << "Print X coordinate: ";
		cin >> location.x;
		if (!cin.good() || location.x < 0) {
			throw COORDINATES_OUT_OF_RANGE;
		}
		cout << "Print Y coordinate: ";
		cin >> location.y;
		if (!cin.good() || location.y < 0) {
			throw COORDINATES_OUT_OF_RANGE;
		}
	} catch (TreeException ex) {
		cout << "Incorrect coordinates!" << endl << endl;  return;
	}
	park.cutByFilter(LOCATION, defaultSpecies, defaultAge, location);
	cout << endl;
}

void ParkInterface :: cutInterface() {
	cout << "Which of this parametres do you want to cut trees by ?" << endl;
	cout << "//----------------------------------------------------//" << endl;
	cout << "  species  - press 1" << endl;
	cout << "  age      - press 2" << endl;
	cout << "  location - press 3" << endl;
	cout << "//----------------------------------------------------//" << endl;
	int curOperation = getche() - 48;
	cout << endl;
	switch (curOperation) {
		case 1  : cutBySpeciesInterface();  break;
		case 2  : cutByAgeInterface();      break;
		case 3  : cutByLocationInterface(); break;
		default : 							break;
	}
}

void ParkInterface :: findAverageAgeBySpeciesInterface() {
	cout << "Print species: ";
	String species;
	species.read();
	cout << "Average age by species ";
	species.print();
	cout << " = ";
	(park.findAverageAgeBySpecies(species)).println();
	cout << endl;
}

void ParkInterface :: run() {
	cout << "//--------------------------------------------//" << endl;
	cout << "// This program for work with database \"Park\" //" << endl;
	cout << "//--------------------------------------------//" << endl;
	cout << endl;
	while (true) {
		printMainMenu();
		int curOperation;
		curOperation = getche() - 48;
		cout << endl << endl;
		if (curOperation == 5) {
			break;
		}
		switch (curOperation) {
			case 1  : addInterface();                     break;
			case 2  : cutInterface();                     break;
			case 3  : findAverageAgeBySpeciesInterface(); break;
			case 4  : park.print();                       break;
			default :                                     break;
		}	
	}
	cout << endl;
	cout << "//--------------------------------------------//" << endl;
	cout << "//      Thank you for using this program      //" << endl;
	cout << "//--------------------------------------------//" << endl;
	park.printInBinaryFile(dataBaseName.c_str());
}
