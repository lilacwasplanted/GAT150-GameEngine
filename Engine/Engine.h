#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fmod.hpp>
#include <memory>
#include "Renderer.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "E_Time.h"
#include "MathUtils.h"
#include"Model.h"
#include "Transform.h"
#include "Audio.h"
#include <SDL.h>
#include <memory>


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


