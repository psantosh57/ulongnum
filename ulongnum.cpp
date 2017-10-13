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
static bool verbose = true;
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
		if (_string.getLength() == 1 && _string.getChar(0) == '0' && !this->_set) {
			_string.setCharAtIndex(0, ch);
			this->_set = true;
		}
		else {
			_string = _string + ch;
		}
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

void ulongnum::mult(const ulongnum& lhs, const ulongnum& rhs) {

	int indLhs = lhs._string.getLength() - 1;
	int indRhsMax = rhs._string.getLength() - 1;
	int indLhsMax = lhs._string.getLength() - 1;
	int indRhs = indRhsMax;
	//ulongnum temp(0, true);
	int carry = 0;
	int result = 0;

	if (indRhs < indLhs) {

		while (indRhs >= 0) {

			int u2 = rhs._string.getChar(indRhs) - '0';
			ulongnum temp(0, true);
			for (int i = indRhsMax; i > indRhs; --i) {

				if (temp._string.getLength() == 1 && temp._string.getChar(0) == '0' && !temp._set) {
					temp._string.setCharAtIndex(0, '0');
					temp._set = true;
				}
				else {

					temp._string = temp._string + '0';
				}

			}

			while (indLhs >= 0) {

				int u1 = lhs._string.getChar(indLhs) - '0';
				result = (u1*u2) + carry;
				carry = result / 10;
				result = result % 10;
				char ch = '0' + result;
				if (temp._string.getLength() == 1 && temp._string.getChar(0) == '0' && !temp._set) {
					temp._string.setCharAtIndex(0, ch);
					temp._set = true;
				}
				else {
					temp._string = temp._string + ch;
				}

				indLhs--;
				

			}

			if (carry) {

				char ch = '0' + carry;
				temp._string = temp._string + ch;
				carry = 0;

			}

			temp._string.reverse();
			*this = *this + temp;
			indRhs--;
			indLhs = lhs._string.getLength() - 1;
		}

	}
	else {

		while (indLhs >= 0) {

			int u2 = lhs._string.getChar(indLhs) - '0';
			ulongnum temp(0, true);
			for (int i = indLhsMax; i > indLhs; --i) {

				if (temp._string.getLength() == 1 && temp._string.getChar(0) == '0' && !temp._set) {
					temp._string.setCharAtIndex(0, '0');
					temp._set = true;
				}
				else {

					temp._string = temp._string + '0';
				}
			}

			while (indRhs >= 0) {

				int u1 = rhs._string.getChar(indRhs) - '0';
				result = (u1*u2) + carry;
				carry = result / 10;
				result = result % 10;
				char ch = '0' + result;
				if (temp._string.getLength() == 1 && temp._string.getChar(0) == '0' && !temp._set) {
					temp._string.setCharAtIndex(0, ch);
					temp._set = true;
				}
				else {
					temp._string = temp._string + ch;
				}


				indRhs--;


			}

			if (carry) {

				char ch = '0' + carry;
				temp._string = temp._string + ch;
				carry = 0;

			}

			temp._string.reverse();
			*this = *this + temp;
			indLhs--;
			indRhs = rhs._string.getLength() - 1;
		}

	}

}

bool ulongnum::compare(const ulongnum& rhs) const {

	return (_string == rhs._string);

}


ulongnum ulongnum::multAlgo(const ulongnum& lhs, const ulongnum& rhs) {

	ulongnum temp1(0, verbose);
	ulongnum temp2(0, verbose);
	ulongnum temp3(0, verbose);
	ulongnum temp4(0, verbose);

	int indLhs = lhs._string.getLength();
	int indRhs = rhs._string.getLength();
	int midLhs = indLhs / 2;
	int midRhs = indRhs / 2;
	int n = 0;

	if (indLhs != indRhs) {

		if ((indLhs % 2 != 0) || (indRhs % 2 != 0)) {

			if (indLhs <= indRhs) {

				n = midRhs + 1;
				temp3._string.buildString(rhs._string, 0, (midRhs - 1));
				temp4._string.buildString(rhs._string, midRhs, (indRhs - 1));
				if (indLhs <= n) {
					//ex - 56*12345 - dont need temp1 (0), temp2 = 56, temp3 = 12, temp4 = 345
					temp2._string.buildString(lhs._string, 0, (indLhs - 1));
				}
				else {

					temp1._string.buildString(lhs._string, 0, (midLhs - 1));
					temp2._string.buildString(lhs._string, midLhs, (indLhs - 1));
				}

			}
			else {

				n = midLhs + 1;
				temp1._string.buildString(lhs._string, 0, (midLhs - 1));
				temp2._string.buildString(lhs._string, midLhs, (indLhs - 1));
				if (indRhs <= n) {
					//ex - 12345*56 - dont need temp3(0), temp1 = 12, temp2 = 345, temp4 = 56
					temp4._string.buildString(rhs._string, 0, (indRhs - 1));
				}
				else {

					temp3._string.buildString(rhs._string, 0, (midRhs - 1));
					temp4._string.buildString(rhs._string, midRhs, (indRhs - 1));

				}

				
			}

		}

	}

	

	

#if 0
	if (indLhs <= midRhs) {

		temp2._string.buildString(lhs._string, 0, (indLhs - 1));
		n = midRhs;

	}
	else if (indRhs <= midLhs) {

		temp4._string.buildString(rhs._string, 0, (indRhs - 1));
		n = midLhs;

	}
	else if ((indLhs > midRhs) && indRhs == 3) {



	}


	else {

		temp1._string.buildString(lhs._string, 0, (midLhs - 1));
		temp2._string.buildString(lhs._string, midLhs, (indLhs - 1));
		temp3._string.buildString(rhs._string, 0, (midRhs - 1));
		temp4._string.buildString(rhs._string, midRhs, (indRhs - 1));


	}

#endif // 0

	int lenTemp1 = temp1.getLen();
	int lenTemp2 = temp2.getLen();
	int lenTemp3 = temp3.getLen();
	int lenTemp4 = temp4.getLen();

	cout << temp1._string << endl;
	cout << temp2._string << endl;
	cout << temp3._string << endl;
	cout << temp4._string << endl;

	bool lhsAll1 = false;
	bool rhsAll1 = false;
	bool all1 = false;
	bool lhs1Or2 = false;
	bool rhs1Or2 = false;
	bool lhs1Or2AndRhs1 = false;
	bool rhs1Or2AndLhs1 = false;
	bool lhs1Or2AndRhs1Or2 = false;

	if ((lenTemp1 == lenTemp2 == 1)) {

		lhsAll1 = true;
	}

	if ((lenTemp3 == lenTemp4 == 1)) {

		rhsAll1 = true;

	}

	if (lhsAll1 && rhsAll1) {

		all1 = true;
		n = 1;
	}

	if ((lenTemp1 == 1 && lenTemp2 == 2) || (lenTemp1 == 2 && lenTemp2 == 1)) {

		lhs1Or2 = true;

	}

	if ((lenTemp3 == 1 && lenTemp4 == 2) || (lenTemp3 == 2 && lenTemp4 == 1)) {

		rhs1Or2 = true;

	}

	if (lhs1Or2 && rhsAll1) {

		lhs1Or2AndRhs1 = true;
		n = 2;
	}

	if (rhs1Or2 && lhsAll1) {

		rhs1Or2AndLhs1 = true;
		n = 2;
	}

	if (rhs1Or2 && lhs1Or2) {

		lhs1Or2AndRhs1Or2 = true;
		n = 2;
	}




	if (lhs1Or2AndRhs1 || rhs1Or2AndLhs1 || all1 || lhs1Or2AndRhs1Or2) {
		cout << "Reached final stage, now computing!" << endl;
		
#if 0
		if (!all1) {

			n = 2;

		}
#endif // 0

		
		
		int b2m = pow(10, (2 * n));
		int bm = pow(10, n);
		ulongnum z2(b2m, true);
		ulongnum z1(bm, true);
		ulongnum product(0, true);
		product.mult(temp1, temp3);
		ulongnum a(0, verbose);
		ulongnum b3(0, verbose);
		ulongnum b1(0, verbose);
		ulongnum b2(0, verbose);
		ulongnum b(0, verbose);
		ulongnum c(0, verbose);
		a.mult(product, z2);
		b1.mult(temp1, temp4);
		b2.mult(temp2, temp3);
		b3 = b1 + b2;
		b.mult(b3,z1);
		c.mult(temp2, temp4);

		//ulongnum answer(0, verbose);
		*this = a + b + c;

		return *this;


	}
	else {

		n = lenTemp1;

		int b2m = pow(10, 2 * n);
		int bm = pow(10, n);

		ulongnum XhYh = multAlgo(temp1, temp3);
		ulongnum XhYl = multAlgo(temp1, temp4);
		ulongnum XlYh = multAlgo(temp2, temp3);
		ulongnum XlYl = multAlgo(temp2, temp4);
		ulongnum a(0, verbose);
		ulongnum b3(0, verbose);
		ulongnum b1(0, verbose);
		ulongnum b2(0, verbose);
		ulongnum b(0, verbose);
		ulongnum c(0, verbose);
		ulongnum z2(b2m, true);
		ulongnum z1(bm, true);
		ulongnum product(0, true);

		a.mult(XhYh, z2);
		b1 = XhYl + XlYh;
		b2.mult(b1, z1);
		
		product = a + b2 + XlYl;

		return product;

	}

	//return 1;

}



//EOF


