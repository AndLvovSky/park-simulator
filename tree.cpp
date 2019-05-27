#include "tree.h"
#include "_string.h"
#include "age.h"
#include "coordinates.h"
#include <ctime>
#include <iostream>

using namespace std;

Tree :: Tree() {
}

Tree :: Tree(String species, time_t plantTime, Coordinates location) {
	this->species   = species;
	this->plantTime = plantTime;
	this->location  = location;
}

Age Tree :: getAge() {
	return ::getAge(plantTime);	
}

void Tree :: setPlantTime(time_t plantTime) {
	this->plantTime = plantTime;
}

void Tree :: print() {
	cout << "species: ";
	species.print();
	cout << ";  age: ";
	getAge().print(); 
	cout << ";  location: x = " << location.x << ", y = " << location.y << ".\n";
}
