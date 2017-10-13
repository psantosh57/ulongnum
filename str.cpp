/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: str.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "str.h"

/*----------------------------------------------------------------
Definition of routines of str class

WRITE CODE IN THIS FILE
-----------------------------------------------------------------*/


void str::reverse() {

	for (int i = 0, j = (_strlen-1); i < j; ++i, --j) {

		char tempCh = _string[i];
		_string[i] = _string[j];
		_string[j] = tempCh;

	}

}

int string_compare(const str& lhs, const str& rhs) {

	int indLhs = 0;
	int indRhs = 0;

	if (lhs._strlen == rhs._strlen) {

		while (lhs._string[indLhs] != '\0' && rhs._string[indRhs] != '\0') {

			if (lhs._string[indLhs] != rhs._string[indRhs]) {

				return (lhs._string[indLhs] - rhs._string[indRhs]);

			}

			indLhs++;
			indRhs++;
		}

		return 0;
	}
	else {

		return (lhs._strlen - rhs._strlen);

	}

}

int str::getLength() const {

	return _strlen;
}

char str::getChar(int index) const {

	return _string[index];
}

void str::buildString(const str& s, int startInd, int endInd) {

	int index = startInd;
	_strlen = (endInd - startInd) + 1;
	while (index <= endInd) {

		_string[(index-startInd)] = s._string[index];
		index++;
	}

	_string[index-startInd] = '\0';


}

void str::setCharAtIndex(int index, const char ch) {

	_string[index] = ch;
}

void str::stripZeros() {

	//int count = 0;
	reverse();
	int i = _strlen-1;
	while (i >= 0 && _string[i] == '0') {
		i--;
		//_strlen--;
	}
	_strlen = i + 1;

	reverse();

	_string[_strlen] = '\0';

	
}

bool str::ifZero() {

	int i = 0;
	while (_string[i] != '\0') {
		if (_string[i] != '0') {
			return false;
		}
		i++;
	}

	return true;

}

//EOF


