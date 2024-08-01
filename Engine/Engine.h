#pragma once
#include "Core/ETime.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"



#include "Renderer/Renderer.h"
#include "Renderer/Particle.h"
//#include "ParticleSystem.h"
//#include "Text.h"
//#include "Font.h"
#include"Renderer/Model.h"


#include <iostream>
#include <cstdlib>
#include <ctime>

//** Input **
#include "Input.h"

//** Audio **
#include "Audio/Audio.h"

//** Math **
#include "Vector2.h"
#include "Random.h"
#include "MathUtils.h"
#include "Transform.h"
//** Framework **
#include "Actor.h"
#include "Scene.h"
#include "Game.h"

#include <fmod.hpp>
#include <SDL.h>
#include <memory>
#include <cassert>


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
	std::unique_ptr<Time> m_time;
	std::unique_ptr<Renderer> m_renderer;
	Input* m_input{ nullptr };
	Audio* m_audio{ nullptr };
};

extern Engine g_engine;


