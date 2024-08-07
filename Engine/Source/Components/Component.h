#pragma once
#include "../Framework/Object.h"

class Component : public Object {
public:
	virtual void Update(float dt) override;

public:
	class Actor* owner{nullptr}

};