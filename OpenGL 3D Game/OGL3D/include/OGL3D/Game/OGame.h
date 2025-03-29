#pragma once
#include <memory>
#include <OGL3D/Graphics/OGraphicsEngine.h>

class OWindow;
class OGame
{
public:
	OGame();
	~OGame();

	virtual void onCreate();
	virtual void onUpdate();
	virtual void onQuit();

	void Run();
	void Quit();
protected:
	bool m_isRunning = true;
	std::unique_ptr<OGraphicsEngine> m_graphicsEngine;
	std::unique_ptr<OWindow> m_display;

	OVertexArrayObjectPtr m_triangleVAO;
};

