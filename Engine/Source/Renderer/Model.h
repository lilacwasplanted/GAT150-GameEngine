#pragma once
#include "../Math/Vector2.h"
#include "../Math/Transform.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/Color.h"
#include <vector>

class Model
{
public:

	Model() = default;
	Model(const   vector<Vector2>& points, const Color& color) : m_points{ points }, m_color{ color } {}

	void Draw(Renderer& renderer, const Transform& transform);
	float GetRadius();

private:
	  vector <Vector2> m_points;
	Color m_color;
};

