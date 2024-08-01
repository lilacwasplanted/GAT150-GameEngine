#include "EFile.h"
using namespace filesystem;

string File::GetFilePath()
{
    return current_path().string();
}

bool File::SetFilePath(const string filepath)
{
    error_code ec;
    current_path(filepath, ec);
    return !ec;
}
