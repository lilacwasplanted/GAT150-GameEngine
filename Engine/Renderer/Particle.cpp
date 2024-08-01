#include "Particle.h"
using namespace std;

void Particle::Update(float dt)
{
	position = position + (velocity * dt);
}

void Particle::Draw(Renderer renderer)
{
	renderer.DrawPoint(position.x, position.y);
	renderer.DrawRect(position.x, position.y, 25.0f, 25.0f);
}
