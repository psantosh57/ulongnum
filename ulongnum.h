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

	ulongnum(int n, bool verbose = false) : _string("", verbose), _display(verbose), _set(false) {

		if (_display) {

			cout << "In ulongnum constructor" << endl;
		}

		int2String(n);
	}

	ulongnum() : _string("1", false), _display(false), _set(false) {

		if (_display) {

			cout << "In default constructor" << endl;
		}


	}

	ulongnum(const char* ch, bool verbose = false) : _string(ch, verbose), _display(verbose) {

		if (_display) {

			cout << "In ulongnum char* constructor" << endl;
		}
	}

	ulongnum(const char ch, bool verbose = false) : _string(ch, verbose), _display(verbose) {

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

		ulongnum sum("", lhs._display);

		sum.add(lhs, rhs);
		return sum;

	}

	friend ulongnum operator+(const int n, const ulongnum& rhs) {

		ulongnum sum(0, rhs._display);

		sum.add(n, rhs);
		return sum;

	}

	friend ulongnum operator+(const ulongnum& lhs, const int n) {

		ulongnum sum(0, lhs._display);

		sum.add(lhs, n);
		return sum;

	}

	friend bool operator==(const ulongnum& lhs, int n) {

		return (lhs.compare(n));

	}

	friend bool operator==(const ulongnum& lhs, const ulongnum& rhs) {

		return (lhs.compare(rhs));

	}

	friend bool operator==(const ulongnum& lhs, const char* ch) {

		return (lhs.compare(ch));

	}

	friend bool operator!=(const ulongnum& lhs, const ulongnum& rhs) {

		return (!lhs.compare(rhs));

	}

	friend ulongnum operator*(ulongnum& lhs, ulongnum& rhs) {

		ulongnum result(0, lhs._display);

		//result = multAlgo(lhs, rhs);
		result.mult(lhs, rhs);

		return result;
	}

	void int2String(int n);
	void add(const ulongnum& lhs, const ulongnum& rhs);
	void add(int n, const ulongnum& rhs);
	void add(const ulongnum& lhs, int n);
	bool compare(int n) const;
	bool compare(const ulongnum& rhs) const;
	bool compare(const char* ch) const;
	ulongnum mult(const ulongnum& lhs, const ulongnum& rhs);
	friend ulongnum multAlgo(const ulongnum& lhs, const ulongnum& rhs);
	int getLen() { return _string.getLength(); };
	ulongnum factorial(ulongnum n);
	void set_display(bool val) {  _display = val; };
	void addZeros(int limit);
	friend void preMult(ulongnum& lhs, ulongnum& rhs);

private:
  bool _display;
  str _string;
  bool _set;


  //Cannot use any STL object
  //must use str object

  //Can have any private functions here

  

};



#endif
//EOF

