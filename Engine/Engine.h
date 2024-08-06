#pragma once
//** Core **
#include "Core/ETime.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"

//** Renderer **
#include "Renderer/Renderer.h"
#include "Renderer/Particle.h"
//#include "ParticleSystem.h"
//#include "Text.h"
//#include "Font.h"
#include"Renderer/Model.h"
#include "Renderer/Texture.h"

//** Input **
#include "Input/Input.h"

//** Audio **
#include "Audio/Audio.h"

//** Math **
#include "Math/Vector2.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"

//** Framework **
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"

//** Resource ** 
#include "Resource/ResourceManager.h"
#include "Resource/Resource.h"

#include <fmod.hpp>
#include <SDL.h>
#include <memory>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>


#define RENDERER g_engine.GetRenderer()

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void ShutDown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }

	Time& GetTime() { return *m_time; }

	bool IsQuit() { return quit; }

private:
	bool quit{ false };
	  unique_ptr<Time> m_time;
	  unique_ptr<Renderer> m_renderer;
	Input* m_input{ nullptr };
	Audio* m_audio{ nullptr };
};

extern Engine g_engine;


