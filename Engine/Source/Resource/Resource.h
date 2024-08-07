#pragma once
#include <string>
#include <memory>

using namespace std;

class Resource {
public:
	Resource() = default;
	~Resource() = default;

	virtual bool Create(string name, ...) = 0;;

};
template<typename T = Resource>
using res_t = shared_ptr<T>;