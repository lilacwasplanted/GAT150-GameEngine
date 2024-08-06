#pragma once
#include "C:/Users/sombr/Neumont College Of Computer Science/Year I/Summer/Intro To Game Programming/GAT150 GameEngine/Engine/Resource/Resource.h"
#include<SDL_ttf.h>
#include<string>

class Font : public Resource
{
public:

	Font() = default;
	~Font();

	bool Create(string name, ...) override;
	bool Load(const string& filename, int fontSize);

	friend class Text;

private:
	_TTF_Font* m_ttffont{ nullptr };
};

