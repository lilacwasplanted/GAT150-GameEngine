#include "EFile.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace filesystem;
//#define PC
//#define SWITCH


string File::GetFilePath()
{
    return current_path().string();
//#ifdef PC
//   return current_path().string();
//#endif //PC
//#ifdef SWITCH
//    return "switch";
//#endif//switch
}

bool File::SetFilePath(const string& filepath)
{
    error_code ec;
    current_path(filepath,ec);
    return !ec;
}

bool File::FileExists(const string& filepath)
{


    return exists(filepath);
}

int File::GetFileSize(const string& filepath, int& size)
{
    error_code ec;
    size = (int)file_size(filepath, ec);
    return !ec;
}

bool File::ReadFile(const string& filepath, string& br)
{
    if (!FileExists(filepath)) {
        cerr << "File does not exist: " << filepath << endl;
     return false;
    }
    ifstream stream(filepath, ios::in); 
    if (!stream.is_open()) {
        cerr << "Could not open file: " << filepath << endl;
        return false;
    }

    ostringstream ostream;
    ostream << stream.rdbuf();

    buffer << ostream.rdbuf();

    return true;
}

bool File::SetFilePath(const string& filepath)
{
    error_code ec;
    current_path(filepath, ec);
    return !ec;
}
