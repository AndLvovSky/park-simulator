#ifndef _STRING_H
#define _STRING_H

#include <iostream>

using namespace std;

const int MAX_SPECIES_LENGTH = 100;

struct String {
	
	char s[MAX_SPECIES_LENGTH];
	
	bool operator == (String a);
	bool operator > (String a);
	bool operator < (String a);
	void set_from_string(string s);
	void read();
	void print();
	void println();
};

String string_to_String(string s);

#endif // _STRING_H
