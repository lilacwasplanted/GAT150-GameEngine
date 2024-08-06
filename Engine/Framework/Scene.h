#pragma once
#include <list>
#include <memory>

class Game;
class Actor;
class Renderer;

using namespace std;

class Scene
{
public:
	Scene() = default;
	Scene(Game* game) : m_game{ game } {}

	void Update(float dt);
	void Draw(Renderer& renderer);
	void AddActor(unique_ptr<Actor> actor);
	void RemoveAll();



	template<typename T>
	T* GetActor();

	Game* GetGame() { return m_game; }

protected:
	Game* m_game{ nullptr };
	list <unique_ptr<Actor>> m_actors;




};

template<typename T>
T* Scene::GetActor() {
	for (auto& actor : m_actors) {
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}
	return nullptr;
}

