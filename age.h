#ifndef AGE_H
#define AGE_H

#include <ctime>
#include <iostream>

using namespace std;

typedef long long li;

const li SECONDS_IN_DAY = 24 * 60 * 60,
	   	 SECONDS_IN_YEAR = 365 * SECONDS_IN_DAY,
	   	 SECONDS_IN_MONTH = 30 * SECONDS_IN_DAY; 

struct Age {
	li years, months;
	
	bool operator == (Age a);
	bool operator > (Age a);
	bool operator < (Age a);
	void print();
	void println();
};

Age getAge(time_t curTime);
time_t getPlantTime(Age age);

#endif // AGE_H
