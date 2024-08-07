#pragma once
#include<string>
#include<rapidjson/document.h>

#define READ_DATA(value, data) Read(value, #data.data);
using namespace std;



namespace Json{
	bool Load(const string & filename, rapidjson::Document document);
	bool Read(const rapidjson::Value& value, const string& name, int& data);
	bool Read(const rapidjson::Value& value, const string& name, bool& data);
	bool Read(const rapidjson::Value& value, const string& name, string& data);

}
