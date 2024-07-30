#include "Audio.h"
#include <iostream>


bool Audio::Initialize()
{
	//FMOD::System* audio;
	//FMOD::System_Create(&audio);

	FMOD::System_Create(&m_audio);

	void* extradiverdata = nullptr;
	m_audio-> init(32, FMOD_INIT_NORMAL, extradiverdata);

    return true;
}

void Audio::ShutDown()
{
	m_audio->close();
}

void Audio::Update()
{
	m_audio->update();
}

bool Audio::AddSound(const std::string& name)
{
	FMOD::Sound* sound = nullptr;
	m_audio->createSound(name.c_str(), FMOD_DEFAULT, 0, &sound);
	if (sound == nullptr) {
		std::cerr << "Could Not Load Sound: " << name << std::endl;
		return false;}

	m_sounds[name] = sound;
	return true;}

bool Audio::PlaySound(const std::string& name)
{
	//check if sound exists, if not return
	if (m_sounds.find(name) == m_sounds.end()) {
		std::cerr << "Could Not Play Sound: " << name << std::endl;
		if (!AddSound(name))return false;
	}
	m_audio->playSound(m_sounds[name], 0, false, nullptr);
	return true;

}



