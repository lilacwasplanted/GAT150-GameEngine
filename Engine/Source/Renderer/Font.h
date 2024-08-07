#pragma once
#include "../Resource/Resource.h"
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

