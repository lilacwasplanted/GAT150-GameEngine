#pragma once
#include <string>
#include <filesystem>
using namespace std;

namespace File {
	string GetFilePath();
	bool SetFilePath(const string filepath);

}