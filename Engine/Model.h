#pragma once
#include "Vector2.h"
#include <vector>
#include "Renderer.h"
#include "Transform.h"
#include "Color.h"

class Model
{
public:

	Model() = default;
	Model(const std::vector<Vector2>& points, const Color& color) : m_points{ points }, m_color{ color } {}

	void Draw(Renderer& renderer, const Transform& transform);
	float GetRadius();

private:
	std::vector <Vector2> m_points;
	Color m_color;
};

