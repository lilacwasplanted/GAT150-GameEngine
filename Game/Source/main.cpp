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

	cout << __FUNCTION__ << endl;
#ifdef _DEBUG
	cout << "debug\n";
#endif

	int i = 5;
	assert(i == 5);

	int* p = nullptr;
	//assert(p != nullptr);


	while (!engine->IsQuit()) {
	
		engine->Update();

		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();

		engine->GetRenderer().EndFrame();
	}
	engine->ShutDown();

	return 0;
}
