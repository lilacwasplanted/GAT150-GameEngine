#pragma once
#include "C:\Users\sombr\Neumont College Of Computer Science\Year I\Summer\Intro To Game Programming\GAT150 GameEngine\Engine\Vector2.h"
#include <vector>
#include "Renderer.h"
#include "C:\Users\sombr\Neumont College Of Computer Science\Year I\Summer\Intro To Game Programming\GAT150 GameEngine\Engine\Transform.h"
#include "C:\Users\sombr\Neumont College Of Computer Science\Year I\Summer\Intro To Game Programming\GAT150 GameEngine\Engine\Color.h"

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

