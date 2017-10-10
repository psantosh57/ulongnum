/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ulongnum.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ulongnum class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ulongnum_H
#define ulongnum_H

#include "../str/str.h"

/*--------------------------------------------------------
class ulongnum
----------------------------------------------------------*/
class ulongnum {
public:
  //WRITE CODE HERE

	ulongnum(int n, bool verbose) : _string("", verbose), _display(verbose) {

		if (_display) {

			cout << "In ulongnum constructor" << endl;
		}

		while (n > 0) {

			char ch = '0' + (n % 10);

			_string = _string + ch;

			n = n / 10;
		}

		_string.reverse();

	}

	ulongnum(const char* ch, bool verbose) : _string(ch, verbose), _display(verbose) {

		if (_display) {

			cout << "In ulongnum char* constructor" << endl;
		}
	}

	ulongnum(const char ch, bool verbose) : _string(ch, verbose), _display(verbose) {

		if (_display) {

			cout << "In ulongnum char* constructor" << endl;
		}
	}

	ulongnum(const ulongnum& u):_string(u._string), _display(u._display) {

		if (_display) {

			cout << "In ulongnum copy constructor" << endl;
		}

	}

	friend ostream& operator<<(ostream& o, const ulongnum& u) {

		if (u._display) {

			cout << "In operator <<" << endl;
		}

		o << u._string;

		return o;

	}

	ulongnum& operator=(const ulongnum& u) {

		_display = u._display;
		_string = u._string;

		return *this;
	}

	friend ulongnum operator+(const ulongnum& lhs, const ulongnum& rhs) {

		ulongnum sum(0, lhs._display);

		sum._string = lhs._string + rhs._string;

		return sum;

	}




private:
  bool _display;
  str _string;


  //Cannot use any STL object
  //must use str object

  //Can have any private functions here
};

#endif
//EOF

