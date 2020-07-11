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
using std::stoi;
using std::streamsize;
// using std::basic_ios<std::fstream>::eof();
namespace Validate {
bool IsInt(string I) {
	if (I == "0") {
		return true;
	}
	int C = stoi(I);
	if ((int C = stoi(I)) != 0) {
		return true;
	}
	return false;
}  // namespace Validate

bool IsPositive(string I) {
	if (!IsInt(I)) {
		return false;
	}
	if ((int c = stoi(I)) > 0) {
		return true;
	}
	return false;
}
}  // namespace Validate
