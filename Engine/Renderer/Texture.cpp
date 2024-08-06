
#include "Texture.h"
#include "Renderer.h"

#include "../Core/EAssert.h"

#include <iostream>
#include <SDL_image.h>
#include <SDL_render.h>

using namespace std;


Texture::~Texture()
{
	// if texture exists, destroy texture
	if (m_texture != 0) SDL_DestroyTexture(m_texture);
}

bool Texture::Load(const string& filename, Renderer& renderer)
{
	// load image onto surface
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == nullptr)
	{
		cerr << "Could not load image: " << filename << endl;
		return false;
	}

	// create texture from surface, texture is a friend class of renderer
	m_texture = SDL_CreateTextureFromSurface( renderer.m_renderer, surface);
	// once texture is created, surface can be freed up
	SDL_FreeSurface(surface);
	if (m_texture == nullptr)
	{
		cerr << "Could not create texture: " << filename << " " << SDL_GetError() << endl;
		return false;
	}

	return true;
}

bool Texture::Create(string name, ...)
{
	va_list args;
	va_start(args, name);
	Renderer renderer = va_arg(args, Renderer);
	va_end(args);

	return Load(name, renderer);
}



Vector2 Texture::GetSize()
{
	ASSERT(m_texture != nullptr);

	// query the texture for the size
	// https://wiki.libsdl.org/SDL2/SDL_QueryTexture
	SDL_Point size;
	SDL_QueryTexture(m_texture, NULL, NULL, &size.x , &size.y);

	return Vector2(size.x, size.y);
}