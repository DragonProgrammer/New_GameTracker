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
using std::stoi;
using std::streamsize;
namespace Validate {
bool IsInt(string I) {
	if (I == "0") {
		return true;
	}
	try {
		if (stoi(I) != 0) {
			return true;
		}
	} catch (std::invalid_argument) {
		cout << "Input must be numeric\n";
		return false;
	}
	cout << "Why not caught?\n";
	return false;
}  // namespace Validate

bool IsPositive(string I) {
	if (!IsInt(I)) {
		return false;
	}
	if (stoi(I) > 0) {
		return true;
	}
	return false;
}
bool Is3Chars(string I) {
	try {
		if (stoi(I) != 0) {
			cout << "Input must be non-numeric\n";
			return false;
		}
	} catch (std::invalid_argument) {
		if (I.size() != 3) {
			cout << "Must be 3 Letters\n";
			return false;
		}
		if (I.size() == 3) {
			return true;
		}
		return false;
	}
	cout << "chould not get here\n";
	return false;
}
bool IsInRange(string I) {
	if (!IsPositive(I)) {
		return false;
	}
	int test = stoi(I);
	if (1 <= test && test <= 4) {
		return true;
	}
	cout << "Number must be in list of options\n";
	return false;
}
}  // namespace Validate
