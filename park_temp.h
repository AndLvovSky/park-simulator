#include "park.h"

template <typename Type>
bool comparator(Type a, Type b, CompareType compT) {
	switch (compT) {
		case EQUAL   : return a == b;
		case GREATER : return a > b;
		case LESS    : return a < b;
	}
}
