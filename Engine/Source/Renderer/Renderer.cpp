#include "Renderer.h"
#include <iostream>
#include <SDL_image.h>
#include "Texture.h"

using namespace std;

bool Renderer::Initialize()
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cerr << "Error initializing SDL: " << SDL_GetError() << endl;
		return 1;
	}


	// initialize Image SDL, supports BMP, JPG, and PNG
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
	{
		  cerr << "Error initializing SDL Image: " << SDL_GetError() <<   endl;
		return false;
	}

	return true;
}

void Renderer::ShutDown()
{
	IMG_Quit();
}

bool Renderer::CreateWindow(string title, int width, int height)
{
	// create window
// returns pointer to window if successful or nullptr if failed
	m_window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN);
	if (m_window == nullptr)
	{
		cerr << "Error creating SDL window: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	// create renderer                                
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	return true;
}

void Renderer::BeginFrame()
{
	SDL_RenderClear(m_renderer);
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{

	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void Renderer::DrawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	SDL_RenderDrawLineF(m_renderer, x1, y1, x2, y2);
}

void Renderer::DrawPoint(int x, int y)
{
	SDL_RenderDrawPoint(m_renderer, x, y);
}
void Renderer::DrawPoint(float x, float y)
{
	SDL_RenderDrawPointF(m_renderer, x, y);
}

void Renderer::DrawRect(int x, int y, int w, int h)
{
	SDL_Rect rect{ x - w / 2 , y - h / 2, w, h };
	SDL_RenderFillRect(m_renderer, &rect);
}

void Renderer::DrawRect(float x, float y, float w, float h)
{
	SDL_FRect rect{ x - w / 2, y - h / 2, w, h };
	SDL_RenderFillRectF(m_renderer, &rect);
}


void Renderer::DrawTexture(Texture* texture, float x, float y, float angle)
{
	
	Vector2 size = texture->GetSize();

	SDL_FRect destRect;
	destRect.x = x;
	destRect.y = y;
	destRect.w = size.x;
	destRect.h = size.y;

	// https://wiki.libsdl.org/SDL2/SDL_RenderCopyExF
	SDL_RenderCopyExF(m_renderer, texture->m_texture, NULL, &destRect, angle, NULL, SDL_FLIP_NONE);
}