#include "EAssert.h"
#include <iostream>
using namespace std;

void CustomAssert(const   string& expression, const   string& filename, int line) {
	cerr << "Assertion failed: (" << expression << "), file" << filename << ", line " << line << endl;
	abort();
}