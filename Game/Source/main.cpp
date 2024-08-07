#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, char* argv[])
{
	unique_ptr<Engine> engine = make_unique<Engine>();
	engine->Initialize();

	ResourceManager rm = ResourceManager();

	File::SetFilePath("assets");
	cout << File::GetFilePath() << endl;


	string s;
	File::ReadFile("text.txt", s);
	cout << s;

	rapidJson::Document document;
	Json::Load("text.txt", document);

	stirng name;
	int age;
	bool isAwake;

	ReadData(document, age);

	Json::Read(document, "age", age);
	Json::Read(document, "name", name);
	Json::Read(document, "isAwake", isAwake);
	cout << name << " " << age << " " << endl;

	res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("beast.png", engine->GetRenderer());
	res_t<Font> font = ResourceManager::instance().get<Font>();
	unique_ptr<Text> text = make_unique<Text>(font);
	text->Create(engine->GetRenderer(), "Hello!", { 1,1,0,1 });
		
	Transform t{ {30, 30}};
	unique_ptr<Actor> actor = make_unique<Actor>(t);
	unique_ptr<TextureComponent> component = make_unique<TextureComponent>();
	component->texture = texture;
	actor->AddComponent(move(component));



	while (!engine->IsQuit()) {
	
		engine->Update();

		engine->Update(engine->GetTime().GetDeltaTime());

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
