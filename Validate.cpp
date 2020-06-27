#include "Validate.hpp"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::numeric_limits;
using std::streamsize;

int Validate::IsInt() {
	int checked;
	do {
		cout << "Input must be an integer\n";
		cin >> checked;
		// should clear the line
		// cin.ignore(numeric_limits<streamsize>::max, "\n");
		// above has error to look into "invalid conversion from ‘long int (*)()
		// noexcept’ to ‘std::streamsize {aka long int}’ [-fpermissive]"
		cin.ignore(80, '\n');
	} while (!cin.good());  // run once then check if int
	return checked;
}

int Validate::IsPositive() {
	int pos = IsInt();
	if (pos > 0) {
		return pos;
	} else if (pos < 1) {
		cout << "Input an unteger grater then zero\n";
		return IsPositive();
	}
}
