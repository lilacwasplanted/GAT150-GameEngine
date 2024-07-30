#pragma once
#include "Transform.h"
#include "Vector2.h"
#include <string>
#include "Model.h"

class Renderer;

class Scene;

class Actor
{
public:
	Actor() = default;
	Actor(const Transform& transform) : m_transform{ transform } {}
	Actor(const Transform& transform, Model* model) : m_model{model}{}

	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);
	
	void SetDamping(float damping) { m_damping = damping; }
	void SetLifespan(float lifespan) { m_lifespan = lifespan; }

	const Transform& GetTransform() { return m_transform; }
	void SetTag(const std::string& tag) { m_tag = tag; }
	std::string GetTag() { return m_tag; }

	virtual void OnCollision(Actor* actor) = 0;
	float GetRadius() { return (m_model) ? m_model->GetRadius() * m_transform.scale : 0; }


	friend class Scene;
protected:
	bool m_destroyed = false;
	float m_lifespan = 0;
	std::string m_tag;

	Transform m_transform;
	Vector2 m_velocity{ 0,0 };
	float m_damping{ 0 };

	Model* m_model{ nullptr };

};

