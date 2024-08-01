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

	File::SetFilePath("assets");
	cout << File::GetFilePath() << endl;


	while (!engine->IsQuit()) {
	
		engine->Update();

		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();

		engine->GetRenderer().EndFrame();
	}
	engine->ShutDown();

	return 0;
}
