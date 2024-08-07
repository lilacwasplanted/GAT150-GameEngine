#include "Actor.h"
#include "../Source/Components/RendererComponent.h"
using namespace std;


void Actor::Update(float dt)
{

	for (auto& component : m_components) {
		component->Update(dt);
	}

	m_transform.position += (m_velocity * dt);
	m_velocity *= 1.0f / (1.0f + m_damping * dt);

}

void Actor::Draw(Renderer& renderer)
{
	if (m_destroyed) return;

	for (auto& component : m_components) {
		RendererComponent* renderComponent = dynamic_cast<RendererComponent*>(component.get());
		if (renderComponent) {
			renderComponent->Draw(renderer);
		}
	}

}

void Actor::AddComponent(unique_ptr<Component> component)
{
	component->owner = this;
	m_components.push_back(move(component))

}
