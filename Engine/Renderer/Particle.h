#pragma once
#include "../Math/Vector2.h"
#include "Renderer.h"

using namespace std;

struct Particle {

public:
	Vector2 position {0,0};
	Vector2 velocity {0,0};
	float lifespan = 0.0f;

	Particle() = default;
	Particle(Vector2 position, Vector2 velocity) : 	position{ position }, velocity{ velocity } 	{}
	Particle(Vector2 position, Vector2 velocity, float m_lifespan) : position{ position }, velocity{ velocity }, lifespan{m_lifespan} {}

	void Update(float dt);
	void Draw(Renderer renderer);

private:
	float m_lifespan = 0.0f;
};
