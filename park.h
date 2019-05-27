#ifndef PARK_H
#define PARK_H

#include "tree.h"
#include "list.h"

enum TreeFilter {
	SPECIES, AGE, LOCATION
};

enum CompareType {
	EQUAL, GREATER, LESS
};

template <typename Type>
bool comparator(Type a, Type b, CompareType compT);

class Park {
	
	private:
		
		List <Tree> treeList;
	
	public:
		
		void cutByFilter(TreeFilter field, String species, Age age, Coordinates location, CompareType compT = EQUAL);
		void addTree(Tree newTree);
		Age findAverageAgeBySpecies(String species);
		void print();
		void printInBinaryFile(const char *fileName);
		void readFromBinaryFile(const char *fileName);
};

#include "park_temp.h"

#endif // PARK_H
