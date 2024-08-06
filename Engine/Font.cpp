#include "Font.h"
#include <string>
using namespace std;

Font::~Font()
{
}

bool Font::Create(string name, ...)
{
	va_list args;
	va_start(args, name);
	int fontSize = va_arg(args, int);
	va_end(args);

	return Load(name, fontSize);
	
	return false;
}

bool Font::Load(const string& filename, int fontSize)
{
	return false;
}
