#include "coordinates.h"
#include <iostream>

using namespace std;

bool Coordinates :: operator == (Coordinates a) {
	return x == a.x && y == a.y;
}

bool Coordinates :: operator > (Coordinates a) {
	return true;
}

bool Coordinates :: operator < (Coordinates a) {
	return true;
}

void Coordinates :: print() {
	cout << "(" << x << ", " << y << ")";
}

void Coordinates :: println() {
	cout << endl;
}
