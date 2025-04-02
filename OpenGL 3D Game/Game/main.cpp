#include "GameApp.h"
#include <iostream>

int main()
{
	try
	{
		GameApp game;
		game.run();
	}
	catch (const std::exception& e)
	{
		std::wclog << e.what() << std::endl;
		return -1;
	}

	return 0;
}