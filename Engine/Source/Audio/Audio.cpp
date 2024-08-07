#include "Audio.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;


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

bool Audio::AddSound(const string& name)
{
	FMOD::Sound* sound = nullptr;
	m_audio->createSound(name.c_str(), FMOD_DEFAULT, 0, &sound);
	if (sound == nullptr) {
		cerr << "Could Not Load Sound: " << name << endl;
		return false;
	};

	m_sounds[name] = sound;
	return true;}

bool Audio::PlaySound(const string& name)
{
	//check if sound exists, if not return
	if (m_sounds.find(name) == m_sounds.end()) {
		  cerr << "Could Not Play Sound: " << name <<   endl;
		if (!AddSound(name))return false;
	}
	m_audio->playSound(m_sounds[name], 0, false, nullptr);
	return true;

}



