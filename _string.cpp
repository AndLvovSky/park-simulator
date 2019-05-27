#include "_string.h"
#include <iostream>

using namespace std;

bool String :: operator == (String a) {
	for (int i = 0; i < MAX_SPECIES_LENGTH; i++) {
		if (s[i] != a.s[i]) {
			return false;
		}
	}
	return true;
}

bool String :: operator > (String a) {
	return true;
}

bool String :: operator < (String a) {
	return true;
}

void String :: set_from_string(string s) {
	String a = string_to_String(s);
	for (int i = 0; i < MAX_SPECIES_LENGTH; i++) {
		this->s[i] = a.s[i];
	}
}

void String :: read() {
	string species_string;
	getline(cin, species_string);
	if (species_string == "") {
		getline(cin, species_string);
	}
	set_from_string(species_string);
}

void String :: print() {
	for (int i = 0; s[i] != '\0'; i++) {
		cout << s[i];
	}
}

void String :: println() {
	print();
	cout << endl;
}

String string_to_String(string s) {
	String newS;
	for (int i = 0; i < s.size(); i++) {
		newS.s[i] = s[i];
	}
	newS.s[s.size()] = '\0';
	for (int i = s.size() + 1; i < MAX_SPECIES_LENGTH; i++) {
		newS.s[i] = '.';
	}
	return newS;
}
