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

void ulongnum::add(const ulongnum& lhs, const ulongnum& rhs) {

	int indLhs = lhs._string.getLength()-1;
	int indRhs = rhs._string.getLength()-1;


	cout << "Lhs = " << indLhs << endl;
	cout << "Rhs = " << indRhs << endl;

	int carry = 0;
	int result = 0;

	while (indLhs >= 0 && indRhs >= 0) {

		int u1 = lhs._string.getChar(indLhs) - '0';
		int u2 = rhs._string.getChar(indRhs) - '0';

		result = u1 + u2 + carry;
		carry = result / 10;
		result = result % 10;
		indLhs--;
		indRhs--;
		char ch = '0' + result;
		_string = _string + ch;
	}

	if (indRhs < 0 && indLhs >= 0) {
		
		while (indLhs >= 0) {
			
			int u1 = lhs._string.getChar(indLhs) - '0';
			result = u1 + carry;
			carry = result / 10;
			result = result % 10;
			char ch = '0' + result;
			_string = _string + ch;
			indLhs--;

		}
		
	}
	else if (indLhs < 0 && indRhs >= 0) {

		while (indRhs >= 0) {

			int u2 = rhs._string.getChar(indRhs) - '0';
			result = u2 + carry;
			carry = result / 10;
			result = result % 10;
			char ch = '0' + result;
			_string = _string + ch;
			indRhs--;

		}

	}

	if (carry) {

		_string = _string + '1';
	}

	_string.reverse();
	
}

void ulongnum::add(int n, const ulongnum& rhs) {

	int indRhs = rhs._string.getLength() - 1;
	
	int carry = 0;
	int result = 0;

	while (n > 0 && indRhs >= 0) {

		int u1 = n % 10;
		int u2 = rhs._string.getChar(indRhs) - '0';

		result = u1 + u2 + carry;
		carry = result / 10;
		result = result % 10;
		indRhs--;
		n /= 10;
		char ch = '0' + result;
		_string = _string + ch;
	}

	if (indRhs < 0 && n > 0) {

		while (n > 0) {

			int u1 = n % 10;
			result = u1 + carry;
			carry = result / 10;
			result = result % 10;
			n /= 10;
			char ch = '0' + result;
			_string = _string + ch;

		}
		
	}
	else if (n == 0 && indRhs >= 0) {

		while (indRhs >= 0) {

			int u2 = rhs._string.getChar(indRhs) - '0';
			result = u2 + carry;
			carry = result / 10;
			result = result % 10;
			char ch = '0' + result;
			_string = _string + ch;
			indRhs--;

		}

	}

	if (carry) {

		_string = _string + '1';
	}

	_string.reverse();

}

void ulongnum::add(const ulongnum& lhs, int n) {

	int indLhs = lhs._string.getLength() - 1;

	int carry = 0;
	int result = 0;

	while (n > 0 && indLhs >= 0) {

		int u1 = lhs._string.getChar(indLhs) - '0'; 
		int u2 = n % 10;

		result = u1 + u2 + carry;
		carry = result / 10;
		result = result % 10;
		indLhs--;
		n /= 10;
		char ch = '0' + result;
		_string = _string + ch;
	}

	if (indLhs < 0 && n > 0) {

		while (n > 0) {

			int u2 = n % 10;
			result = u2 + carry;
			carry = result / 10;
			result = result % 10;
			n /= 10;
			char ch = '0' + result;
			_string = _string + ch;

		}

	}
	else if (n == 0 && indLhs >= 0) {

		while (indLhs >= 0) {

			int u1 = lhs._string.getChar(indLhs) - '0';
			result = u1 + carry;
			carry = result / 10;
			result = result % 10;
			char ch = '0' + result;
			_string = _string + ch;
			indLhs--;

		}

	}

	if (carry) {

		_string = _string + '1';
	}

	_string.reverse();

}

bool ulongnum::compare(int n) const {

	int indLhs = _string.getLength() - 1;

	while (indLhs >= 0 && n > 0) {

		int u1 = _string.getChar(indLhs) - '0';
		int u2 = n % 10;

		return(u1 == u2);

	}

	return !(indLhs >= 0 || n > 0);

}




//EOF


