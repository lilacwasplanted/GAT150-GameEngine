#pragma once
#include <string>
using namespace std;

#ifdef _DEBUG
#define ASSERT(expr)((expr) ? (void)0 : CustomAssert(#expr, __FILE__, __LINE__))
#else
#define ASSERT(expr)(void)0
#endif

void CustomAssert(const string& expression, const string& filename, int line);