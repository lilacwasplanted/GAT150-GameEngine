#pragma once
//** Core **
#include "../Engine/Source/Core/ETime.h"
#include "../Engine/Source/Core/EAssert.h"
#include "../Engine/Source/Core/EFile.h"

//** Renderer **
#include "../Engine/Source/Renderer/Renderer.h"
#include "../Engine/Source/Renderer/Particle.h"
//#include "ParticleSystem.h"
//#include "Text.h"
#include "../Engine/Source/Renderer/Font.h"
#include "../Engine/Source/Renderer/Model.h"
#include "../Engine/Source/Renderer/Texture.h"

//** Input **
#include "../Engine/Source/Input/Input.h"

//** Audio **
#include "../Engine/Source/Audio/Audio.h"

//** Math **
#include "../Engine/Source/Math/Vector2.h"
#include "../Engine/Source/Math/Random.h"
#include "../Engine/Source/Math/MathUtils.h"
#include "../Engine/Source/Math/Transform.h"

//** Framework **
#include "../Engine/Source/Framework/Actor.h"
#include "../Engine/Source/Framework/Scene.h"
#include "../Engine/Source/Framework/Game.h"

//** Resource ** 
#include "../Engine/Source/Resource/ResourceManager.h"
#include "../Engine/Source/Resource/Resource.h"

//** Component **
#include "../Engine/Source/Components/Component.h"
#include "../Engine/Source/Components/RendererComponent.h"
#include "../Engine/Source/Components/TextureComponent.h"

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


