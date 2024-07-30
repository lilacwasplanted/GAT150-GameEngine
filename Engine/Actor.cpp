#include "Actor.h"
#include "Model.h"

void Actor::Update(float dt)
{

}

void Actor::Draw(Renderer& renderer)
{
	if (m_destroyed) return;
	if (m_model) { m_model->Draw(renderer, m_transform); }
}