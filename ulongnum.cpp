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
static bool verbose = false;
/*----------------------------------------------------------------

Definition of routines of ulongnum class

WRITE ALL CODE HERE
-----------------------------------------------------------------*/
void ulongnum::int2String(int n) {


	if (n == 0) {

		_string = _string + '0';
	}



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

#if 0
		if (!this->_set) {
			_string.setCharAtIndex(0, ch);
			this->_set = true;
		}
		else {
			_string = _string + ch;
		}
#endif // 0





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
		if (_string.getLength() == 1 && _string.getChar(0) == '0' && !this->_set) {
			_string.setCharAtIndex(0, ch);
			this->_set = true;
		}
		else {
			_string = _string + ch;
		}
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
		if (_string.getLength() == 1 && _string.getChar(0) == '0' && !this->_set) {
			_string.setCharAtIndex(0, ch);
			this->_set = true;
		}
		else {
			_string = _string + ch;
		}
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

ulongnum ulongnum::mult(const ulongnum& lhs, const ulongnum& rhs) {

	int indLhs = lhs._string.getLength() - 1;
	int indRhs = rhs._string.getLength() - 1;
	int indLhsMax = indLhs;
	int indRhsMax = indRhs;
	int carry = 0;
	int result = 0;

	if (indRhs < indLhs) {

		int u2 = 0;

		while (indRhs >= 0) {
			if (indRhs > 0) {

				u2 = (rhs._string.getChar(indRhs - 1) - '0') * 10 + (rhs._string.getChar(indRhs) - '0');

			}
			else {
				
				u2 = rhs._string.getChar(indRhs) - '0';

			}
			

			//int u2 = rhs._string.getChar(indRhs) - '0';
			ulongnum temp("", verbose);
			char charAtZero = temp._string.getChar(0);
			for (int i = indRhsMax; i > indRhs; --i) {
				temp._string = temp._string + '0';

			}

			while (indLhs >= 0) {

				//int u1 = (lhs._string.getChar(indLhs - 1) - '0') * 10 + (lhs._string.getChar(indLhs) - '0');
				int u1 = lhs._string.getChar(indLhs) - '0';
				result = (u1*u2) + carry;
				carry = result / 10;
				result = result % 10;
				//char ch = '0' + result;
				temp._string = temp._string + ('0' + result);
				indLhs--;
				//indLhs-=2;
				

			}

			if (carry > 10) {

				while (carry > 0) {

					char ch = '0' + (carry % 10);
					temp._string = temp._string + ch;
					carry = carry / 10;

				}
			}
			else if (carry) {

				char ch = '0' + carry;
				temp._string = temp._string + ch;
				carry = 0;

			}

			temp._string.reverse();
			*this = *this + temp;
			//indRhs--;
			indRhs-=2;
			indLhs = indLhsMax;
		}

		//this->_string.stripZeros();
		return *this;

	}
	else {

		while (indLhs >= 0) {

			int u2 = 0;

			if (indLhs > 0) {

				u2 = (lhs._string.getChar(indLhs - 1) - '0') * 10 + (lhs._string.getChar(indLhs) - '0');
			}
			else {
				
				u2 = lhs._string.getChar(indLhs) - '0';

			}
			
			//int u2 = lhs._string.getChar(indLhs) - '0';
			ulongnum temp("", verbose);
			char charAtZero = temp._string.getChar(0);
			for (int i = indLhsMax; i > indLhs; --i) {

				temp._string = temp._string + '0';

			}

			while (indRhs >= 0) {

				int u1 = rhs._string.getChar(indRhs) - '0';
				result = (u1*u2) + carry;
				carry = result / 10;
				result = result % 10;
				//char ch = '0' + result;
				temp._string = temp._string + ('0' + result);
				indRhs--;


			}

				if (carry > 10) {

					while (carry > 0) {

						char ch = '0' + (carry % 10);
						temp._string = temp._string + ch;
						carry = carry / 10;

					}
				}
				else if (carry) {

					char ch = '0' + carry;
					temp._string = temp._string + ch;
					carry = 0;

				}


			temp._string.reverse();
			*this = *this + temp;

			indLhs -= 2;
			//indLhs--;
			indRhs = indRhsMax;
		}

		//this->_string.stripZeros();
		return *this;

	}

}

bool ulongnum::compare(const ulongnum& rhs) const {

	return (_string == rhs._string);

}


ulongnum multAlgo(const ulongnum& lhs, const ulongnum& rhs) {
	
	ulongnum lhs1(lhs);
	ulongnum rhs1(rhs);

	if (lhs1._string.ifZero() || rhs1._string.ifZero()) {

		return 0;
	}

	int indLhs = lhs1._string.getLength();
	int indRhs = rhs1._string.getLength();

	if (indLhs <= 14 && indRhs <= 14) {
		ulongnum temp("", verbose);
		temp.mult(lhs1, rhs1);
		return temp;

	}
	else {
		int mid = 0;
		(indLhs > indRhs) ? mid = ((indLhs + 1) / 2) : mid = ((indRhs + 1) / 2);
		int n = mid;

		//To make strings of equal length
		if (indLhs < indRhs) {

			int i = indLhs;
			while (i < indRhs) {

				lhs1._string = '0' + lhs1._string;
				i++;
			}
			indLhs = i;

		}
		else if (indRhs < indLhs) {

			int i = indRhs;
			while (i < indLhs) {

				rhs1._string = '0' + rhs1._string;
				i++;
			}
			indRhs = i;

		}


		//To make strings of even length
		if (indLhs % 2 != 0) {
			
			lhs1._string = '0' + lhs1._string;
			indLhs++;
		
			rhs1._string = '0' + rhs1._string;
			indRhs++;

		}

		ulongnum temp1("", verbose);
		ulongnum temp2("", verbose);
		ulongnum temp3("", verbose);
		ulongnum temp4("", verbose);

		temp1._string.buildString(lhs1._string, 0, (mid - 1));
		temp2._string.buildString(lhs1._string, n, (indLhs - 1));
		temp3._string.buildString(rhs1._string, 0, (mid - 1));
		temp4._string.buildString(rhs1._string, n, (indRhs - 1));

		int lenTemp1 = temp1._string.getLength();
		int lenTemp2 = temp1._string.getLength();
		int lenTemp3 = temp1._string.getLength();
		int lenTemp4 = temp1._string.getLength();

		//Base case of recursive function - when len = 2, use default mult

		//Call this function recursively
		 ulongnum XhYh("", verbose);
		ulongnum XhYl("", verbose);			
		ulongnum XlYh("", verbose);			
		ulongnum XlYl("", verbose);			
		ulongnum b1("", verbose);
		ulongnum product("", verbose);

		XhYh = multAlgo(temp1, temp3);
		XhYl = multAlgo(temp1, temp4);
		XlYh = multAlgo(temp2, temp3);
		XlYl = multAlgo(temp2, temp4);

		XhYh.addZeros((2 * n));
		b1 = XhYl + XlYh;
		b1.addZeros(n);

		product = XhYh + b1 + XlYl;
		product._string.stripZeros();
		return product;

		

	}

}

ulongnum ulongnum::factorial(ulongnum n) {

	ulongnum temp(*this+1);
	while (temp != (n+1)) {
		*this = *this*temp;
		temp = temp + 1;
	}

	return *this;

}

void ulongnum::addZeros(int limit) {

	int i = 0;
	while (i < limit) {
		_string = _string + '0';
		i++;
	}

}

void preMult(ulongnum& lhs, ulongnum& rhs) {

	int indLhs = lhs._string.getLength();
	int indRhs = rhs._string.getLength();

	if (indLhs < indRhs) {

		lhs._string.reverse();
		int i = indLhs;
		while (i < indRhs) {

			lhs._string = lhs._string + '0';
			i++;
		}
		indLhs = i;
		lhs._string.reverse();

	}
	else if (indRhs < indLhs) {

		rhs._string.reverse();
		int i = indRhs;
		while (i < indLhs) {

			rhs._string = rhs._string + '0';
			i++;
		}
		indRhs = i;
		rhs._string.reverse(); 

	}

	//To make strings of even length
	if (indLhs % 2 != 0) {
		lhs._string.reverse();
		lhs._string = lhs._string + '0';
		indLhs++;
		lhs._string.reverse();
	}

	if (indRhs % 2 != 0) {
		rhs._string.reverse();
		rhs._string = rhs._string + '0';
		indRhs++;
		rhs._string.reverse();
	}


}

bool ulongnum::compare(const char* ch) const {

	int uLongLen = _string.getLength();
	int strLen = strlen(ch);

	if (uLongLen != strLen) {

		return false;
	}
	else {
		int i = 0;
		while (ch[i] != '\0') {

			if (_string.getChar(i) != ch[i]) {

				return false;
			}
			i++;
		}

		return true;

	}
}


//EOF


