#ifndef COORDINATES_H 
#define COORDINATES_H

struct Coordinates {	
	double x, y;
	
	bool operator == (Coordinates a);
	bool operator > (Coordinates a);
	bool operator < (Coordinates a);
	void print();
	void println();
};

#endif // COORDINATES_H
