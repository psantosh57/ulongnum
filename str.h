/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: str.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has str class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef str_H
#define str_H

#include "../darray/darray.h"

/*----------------------------------------------------------------
Declaration of str class
-----------------------------------------------------------------*/
class str {
public:
   //WRITE CODE HERE

	str(char ch, bool verbose) :_string(2, verbose), _display(verbose), _strlen(1) {

		if (_display) {

			cout << "In str ch constructor" << endl;
		}

		_string[0] = ch;
		_string[1] = '\0';

	}


	str(const char* chArray, bool verbose = false) : _string((strlen(chArray)+1), verbose), _display(verbose), _strlen((strlen(chArray))) {

		if (_display) {

			cout << "In str chArray constructor" << endl;
		}

		int index = 0;
		while (chArray[index] != '\0') {

			_string[index] = chArray[index];
			index++;
		}

		_string[index] = '\0';

	}

	str(const darray<char>& s) : _string(s), _strlen(0) {

		if (_display) {

			cout << "In str darray constructor" << endl;
		}

		int index = 0;
		while (s[index] != '\0') {

			++_strlen;
			++index;
		}

	}

	str(const str& s) : _string(s._string) {

		if (s._display) {

			cout << "In str copy constructor" << endl;
		}

		_display = s._display;
		_strlen = s._strlen;
		
	}


	~str() {

		if (_display) {

			cout << "In str destructor" << endl;
		}
	}

	friend ostream& operator<<(ostream& o, const str& s) {

		if (s._display) {

			cout << "In operator <<" << endl;
		}

		int index = 0;
		while (s._string[index] != '\0') {

			o << s._string[index];
			++index;
		}

		return o;

	}

	str& operator=(const str& rhs) {
	
		if (_display) {

			cout << "In operator =" << endl;
		}

		_display = rhs._display;
		_strlen = rhs._strlen;
		_string = rhs._string;

		return *this;

	}


	friend bool operator==(const str& lhs, const str& rhs) {

		if (lhs._display) {

			cout << "In operator ==" << endl;
		}

		if (lhs._strlen == rhs._strlen) {

			int index = 0;
			while(lhs._string[index] != '\0') {

				if (lhs._string[index] != rhs._string[index]) {
					return false;
				}

				++index;

			}

			return true;

		}
		else {

			return false;
		}

	}

	friend bool operator!=(const str& lhs, const str& rhs) {

		if (lhs._display) {

			cout << "In operator !=" << endl;
		}

		return (!(lhs == rhs));

	}

	friend str operator+(const char ch, const str& rhs) {

		str sum(ch, rhs._display);
		sum._strlen += rhs._strlen;
		int index = 1;
		while (index < sum._strlen) {

			sum._string[index] = rhs._string[index - 1];
			index++;
		}

		sum._string[index] = '\0';
		
		return sum;

	}

	friend str operator+(const str& lhs, const char& ch) {

		str sum(lhs._string);
		sum._strlen += 1;
		int index = (sum._strlen - 1);
		sum._string[index++] = ch;
		sum._string[index] = '\0';
		
		return sum;

	}

	friend str operator+(const str& lhs, const char* ch) {

		str sum(lhs._string);
		sum._strlen += strlen(ch);
		int index = (sum._strlen - strlen(ch));
		int count = 0;
		while (ch[count] != '\0') {
			sum._string[index++] = ch[count++];
		}
		sum._string[index] = '\0';

		return sum;

	}

	void reverse();
	int friend string_compare(const str& lhs, const str& rhs);
	int getLength() const;
	char getChar(int index) const;



private:
  bool _display;
  darray<char> _string;
  int _strlen;
  //Cannot use any STL OBJECT
  //MUST USE darray 
  //Can have any number of private functions
};

#endif
//EOF

