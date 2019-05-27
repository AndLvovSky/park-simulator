#include "park.h"
#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;

void Park :: cutByFilter(TreeFilter field, String species, Age age, Coordinates location, CompareType compT) {
	int pos = 0, cut = 0;
	for (Node <Tree> *it = treeList.begin(); it != NULL; pos++) {
		bool toCut = false;
		switch (field) {
			case SPECIES  : toCut = comparator(it->data.species, species, compT);   break;
			case AGE      : toCut = comparator(it->data.getAge(), age, compT);      break;
			case LOCATION : toCut = comparator(it->data.location, location, compT); break;
		}
		it = it->next;
		if (toCut) {
			treeList.erase(pos--);
			cut++;
		}
	}
	cout << cut << (cut == 1 ? " tree has" : " trees have") << " cut " << endl << endl;
}

void Park :: addTree(Tree newTree) {
	treeList.add(newTree);
}

Age Park :: findAverageAgeBySpecies(String species) {
	time_t curTime = time(NULL);
	li averageSeconds, sumSeconds = 0, numOfTrees = 0;
	for (Node <Tree> *it = treeList.begin(); it != NULL; it = it->next) {
		if (it->data.species == species) {
			sumSeconds += difftime(curTime, it->data.plantTime);
			numOfTrees++;
		}
	}
	averageSeconds = (numOfTrees == 0 ? 0 : sumSeconds / numOfTrees);
	return getAge((time_t)(curTime - averageSeconds));
}

void Park :: print() {
	if (treeList.size() == 0) {
		cout << "Park is empty" << endl << endl;
		return;
	} else if (treeList.size() == 1) {
		cout << "There are 1 tree in the park" << endl;
	} else {
		cout << "Trere are " << treeList.size() << " trees in park" << endl;
	}
	cout << "//----------------------------------------------------//" << endl;
	int i = 1;
	for (Node <Tree> *it = treeList.begin(); it != NULL; it = it->next) {
		cout << "  Tree N" << i++ << ": ";
		it->data.print();
	}
	cout << "//----------------------------------------------------//" << endl;
	cout << endl;
}

void Park :: printInBinaryFile(const char *fileName) {
	ofstream fout(fileName, ios_base :: binary);
	for (Node <Tree> *it = treeList.begin(); it != NULL; it = it->next) {
		fout.write((char*)it, sizeof(Tree));
	}
	fout.close();
}

void Park :: readFromBinaryFile(const char *fileName) {
	ifstream fin(fileName, ios_base :: binary);
	Tree cur;
	while (fin.read((char*)&cur, sizeof(cur))) {
		treeList.add(cur);
	}
	fin.close();
}
