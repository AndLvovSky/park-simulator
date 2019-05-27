#include "age.h"
#include <ctime>
#include <iostream>

using namespace std;

bool Age :: operator == (Age a) {
	return years == a.years && months == a.months;
}

bool Age :: operator > (Age a) {
	return years == a.years && months > a.months || years > a.years;
}

bool Age :: operator < (Age a) {
	return years == a.years && months < a.months || years < a.years;
}

void Age :: print() {
	if (years == 0) { 
		cout << months << " months";
	} else {
		cout << years;
		if (years == 1) {
			cout << " year";
		} else {
			cout << " years";
		}
		if (months != 0) {
			cout << " " << months;
			if (months == 1) {
				cout << " month";
			} else {
				cout << " months"; 
			}
		}
	}
}

void Age :: println() {
	print();
	cout << endl;
}

Age getAge(time_t curTime) {
	li deltaSeconds = (li)difftime(time(NULL), curTime);
	Age age;
	age.years = deltaSeconds / SECONDS_IN_YEAR;
	age.months =  (deltaSeconds - age.years * SECONDS_IN_YEAR) / SECONDS_IN_MONTH;
	return age;
}

time_t getPlantTime(Age age) {
	return (time_t)((li)time(NULL) - (age.years * SECONDS_IN_YEAR + age.months * SECONDS_IN_MONTH));
}
