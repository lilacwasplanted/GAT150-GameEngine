#pragma once
#include <string>
using namespace std;

class Object {
public:
	Object() = default;
	Object(const string& name) : name{name}{}

	virtual void Initialize() = 0;
	virtual void Activate() { active = true; }
	virtual void Deactivate() { active = false; }
	
public:
	string name;
	bool active = false;

};