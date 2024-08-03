#include "Model.h"
#include "C:\Users\sombr\Neumont College Of Computer Science\Year I\Summer\Intro To Game Programming\GAT150 GameEngine\Engine\Math\Vector2.h"
#include "C:\Users\sombr\Neumont College Of Computer Science\Year I\Summer\Intro To Game Programming\GAT150 GameEngine\Engine\Math\Transform.h"
#include "C:\Users\sombr\Neumont College Of Computer Science\Year I\Summer\Intro To Game Programming\GAT150 GameEngine\Engine\Renderer\Color.h"


void Model::Draw(Renderer& renderer, const Transform& transform)
{
    if (m_points.empty()) return;
    renderer.SetColor(Color::ToInt(m_color.r), Color::ToInt(m_color.g), Color::ToInt(m_color.b), Color::ToInt(m_color.a));
    for (int i = 0; i < m_points.size() - 1; i++) {
        Vector2 p1 = m_points[i].Rotate(transform.rotation) * transform.scale + transform.position;
        Vector2 p2 = m_points[i + 1].Rotate(transform.rotation) * transform.scale + transform.position;

        renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
    }
}

float Model::GetRadius()
{
    float radius = 0;
    for (const Vector2& point : m_points) {
        float r = point.Length();
        if (r > radius) {
            radius = r;
        }
    }
    return radius;
}
