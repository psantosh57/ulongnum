/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ulongnum.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"
/*----------------------------------------------------------------

Definition of routines of ulongnum class

WRITE ALL CODE HERE
-----------------------------------------------------------------*/
void ulongnum::int2String(int n) {

	while (n > 0) {

		char ch = '0' + (n % 10);

		_string = _string + ch;

		n = n / 10;
	}

	_string.reverse();
}

void add(const ulongnum& lhs, const ulongnum& rhs) {

	int indLhs = lhs._string.getLength();
	int indRhs = lhs._string.getLength();

	cout << "Lhs = " << indLhs << endl;
	cout << "Rhs = " << indRhs << endl;

	int carry = 0;
	//int lhs = lhs._string[indLhs] - '0';

}




//EOF


