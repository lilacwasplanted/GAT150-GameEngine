#include "Engine.h"
#include "Resource/ResourceManager.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include "Font.h"

using namespace std;

int main(int argc, char* argv[])
{
	unique_ptr<Engine> engine = make_unique<Engine>();
	engine->Initialize();

	ResourceManager rm = ResourceManager();

	File::SetFilePath("assets");
	cout << File::GetFilePath() << endl;

	res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("beast.png", engine->GetRenderer());


	while (!engine->IsQuit()) {
	
		engine->Update();

		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();
		engine->GetRenderer().DrawTexture(texture.get(), randomf(800), randomf(600), random(360));
	/*	for (int i = 0; i < 50; i++) {
			engine->GetRenderer().DrawTexture(texture.get(), randomf(800), randomf(600));
		}*/

		engine->GetRenderer().EndFrame();
	}
	engine->ShutDown();

	return 0;
}
