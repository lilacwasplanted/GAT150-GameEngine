#pragma once
#include "C:/Users/sombr/Neumont College Of Computer Science/Year I/Summer/Intro To Game Programming/GAT150 GameEngine/Engine/Math/Vector2.h"
#include "C:/Users/sombr/Neumont College Of Computer Science/Year I/Summer/Intro To Game Programming/GAT150 GameEngine/Engine/Renderer/Renderer.h"
#include "C:/Users/sombr/Neumont College Of Computer Science/Year I/Summer/Intro To Game Programming/GAT150 GameEngine/Engine/Renderer/Color.h"
#include "C:/Users/sombr/Neumont College Of Computer Science/Year I/Summer/Intro To Game Programming/GAT150 GameEngine/Engine/Math/Transform.h"
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

