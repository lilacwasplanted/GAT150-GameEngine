#pragma once
#include <string>
#include <filesystem>
using namespace std;

namespace File {
	string GetFilePath();
	bool SetFilePath(const string& filepath);
	bool FileExists(const string& filepath);
	int GetFileSize(const string& filepath, int& size);
	bool ReadFile(const string& filepath, string& br);

}