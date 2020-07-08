//#include "Validate.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
// using std::basic_ios<std::fstream>::eof();
namespace Validate {
int IsInt() {
	int checked;
	do {
		cout << "Input must be an integer\n";
		if (cin >> checked) {
			return checked;
		}
		cout << checked;
		// should clear the line
		// cin.ignore(numeric_limits<streamsize>::max, "\n");
		cin.ignore(80, '\n');
	}

	while (!cin.fail());  // run once then check if int
	return -23636;
}  // namespace Validate

int IsPositive() {
	int pos = IsInt();
	cout << pos << endl;
	if (pos == -23636) {
		return -1;
	}

	if (pos > 0) {
		return pos;
	} else if (pos < 1) {
		cout << "Input an unteger grater then zero\n";
		return IsPositive();
	}
	return -1;
}
}  // namespace Validate
