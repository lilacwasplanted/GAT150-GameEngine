#pragma once
#include <string>
#include "../Resource/Resource.h"
#include "../Math/Vector2.h"

using namespace std;



class Texture : public Resource
{
public:
	Texture() = default;
	~Texture();

	bool Create(string name, ...) override;
	bool Load(const string& filename, class Renderer& renderer);
	

	Vector2 GetSize();

	friend class Renderer;

private:
	struct SDL_Texture* m_texture{ nullptr };
};