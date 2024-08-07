#pragma once
#include "Resource.h"
#include <string>
#include <map>
#include <iostream>
#include "../Core/Singleton.h"

using namespace std;

class ResourceManager : public Singleton<ResourceManager> {
public:
	template <typename T, typename ... TArgs>
	res_t<T> Get(const string& name, TArgs ... args);



private:
	map<string, res_t<Resource>> m_resources;


};

template<typename T, typename ... TArgs>
inline res_t<T> ResourceManager::Get(const string& name, TArgs ... args)
{
	//find resourc in resource manager
	if (m_resources.find(name) != m_resources.end()) {
		return dynamic_pointer_cast<T>(m_resources[name]);
	}
	//resource not found, create resource
	res_t<T> resource = make_shared<T>();
	if (!resource->Create(name, args...)) {
		//resource not created
		cerr << "Could not create resource: " << name <<endl;
		return res_t<T>();
	}

	//add resource to resouce manager
	m_resources[name] = resource;

	return resource;



}
