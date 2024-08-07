#include "Json.h"
#include "EFile.h"
#include <rapidjson/istreamwrapper.h>
#include <istream>
#include <iostream>
using namespace std;


bool Json::Load(const string& filename, rapidjson::Document document)
{
    string buffer;
    if (!File::ReadFile(filename, buffer)) {
        return false;

    }
    stringstream stream(buffer);
    rapidjson::IStreamWrapper istream(stream);
    document.ParseStream(istream);
    if (!document.IsObject()) {
        cerr << "Could not parse Json:" << filename << endl;
        return false;
    }



    return true;
}

bool Json::Read(const rapidjson::Value& value, const string& name, int& data)
{
    if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsInt()) {
        cerr << "Could not read Json:" << name << endl;
    }
    data = value[name.c_str()].GetInt();
    return true;
}

bool Json::Read(const rapidjson::Value& value, const string& name, bool& data)
{
    if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsBool()) {
        cerr << "Could not read Json:" << name << endl;
    }
    data = value[name.c_str()].GetBool();
    return true;
}

bool Json::Read(const rapidjson::Value& value, const string& name, string& data)
{
    if (!value.HasMember(name.c_str()) || !value[name.c_str()].IsString()) {
        cerr << "Could not parse Json:" << name << endl;
    }
    data = value[name.c_str()].GetString();
    return true;
}
