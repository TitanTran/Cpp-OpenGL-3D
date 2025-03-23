#pragma once
#include <memory>

class OWindow;
class OGame
{
public:
	OGame();
	~OGame();

	void Run();
	void Quit();
protected:
	bool m_isRunning = true;
	std::unique_ptr<OWindow> m_display;
};

