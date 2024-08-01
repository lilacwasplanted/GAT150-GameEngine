#include "EAssert.h"
#include <iostream>
using namespace std;

void CustomAssert(const std::string& expression, const std::string& filename, int line) {
	cerr << "Assertion failed: (" << expression << "), file" << filename << ", line " << line << endl;
	abort();
}