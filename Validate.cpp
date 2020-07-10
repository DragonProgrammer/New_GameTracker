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
using std::getline;
using std::numeric_limits;
using std::streamsize;
// using std::basic_ios<std::fstream>::eof();
namespace Validate {
int IsInt() {
	string input;
	int checked;
	cout << "Input must be an integer\n";

	while (getline(cin, input, '\n')) {
		cin.clear();
		if (input == "0") {
			return 0;
		}
		checked = stoi(input);
		if (!checked == 0) {
			return checked;
		}
		cout << "input is not an integer. Try again:\n";
	}

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
