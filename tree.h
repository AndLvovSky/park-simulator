#ifndef TREE_H
#define TREE_H

#include "_string.h"
#include "age.h"
#include "coordinates.h"
#include <ctime>
#include <iostream>

using namespace std;

struct Tree {
	
	String species;
	time_t plantTime;
	Coordinates location;
		
	Tree();
	Tree(String species, time_t plantTime, Coordinates location);
	Age getAge();
	void setPlantTime(time_t plantTime);
	void print();
};

#endif // TREE_H
