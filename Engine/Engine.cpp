#include "Engine.h"

using namespace std;

Engine g_engine;

bool Engine::Initialize()
{
    m_renderer = make_unique<Renderer>();
    m_input = new Input();
    m_audio = new Audio();


    (*m_renderer).Initialize();
    m_renderer->CreateWindow("Game Engine", 800, 600);

    m_input->Initialize();
    m_audio->Initialize();

    m_time = std::make_unique<Time>();

    return true;
}

void Engine::ShutDown()
{
    m_renderer->ShutDown();
    m_input->ShutDown();
    m_audio->ShutDown();


}

void Engine::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }

        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            quit = true;
        }
    }

    m_time->Tick();
    m_input->Update();
    m_audio->Update();
}
