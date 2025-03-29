#include <OGL3D/Graphics/OGraphicsEngine.h>
#include <glad/glad_wgl.h>
#include <glad/glad.h>
#include <assert.h>
#include <OGL3D/Window/OWindow.h>
#include <stdexcept>

OGraphicsEngine::OGraphicsEngine()
{
    WNDCLASSEX windowClass = {};
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = DefWindowProcA;
    windowClass.lpszClassName = L"OGL3DDummyWindow";
    windowClass.cbSize = sizeof(WNDCLASSEX);

    auto classId = RegisterClassEx(&windowClass);

    HWND dummyWindow = CreateWindowEx(
        0,
        MAKEINTATOM(classId),
        L"OGL3DDummyWindow",
        0,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0,
        0,
        windowClass.hInstance,
        0);

    assert(dummyWindow);

    HDC dummyDC = GetDC(dummyWindow);

	PIXELFORMATDESCRIPTOR pixelFormatDesc = {};
	pixelFormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatDesc.nVersion = 1;
	pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixelFormatDesc.cColorBits = 32;
	pixelFormatDesc.cAlphaBits = 8;
	pixelFormatDesc.cDepthBits = 24;
	pixelFormatDesc.cStencilBits = 8;
	pixelFormatDesc.iLayerType = PFD_MAIN_PLANE;

	auto pixelFormat = ChoosePixelFormat(dummyDC, &pixelFormatDesc);
	SetPixelFormat(dummyDC, pixelFormat, &pixelFormatDesc);



    HGLRC dummyContext = wglCreateContext(dummyDC);
    assert(dummyContext);

    bool res = wglMakeCurrent(dummyDC, dummyContext);
    assert(res);

	if (!gladLoadWGL(dummyDC))
	{
		throw std::runtime_error("Failed to load WGL");
	}

	if (!gladLoadGL())
	{
		throw std::runtime_error("Failed to load WGL");
	}

	wglMakeCurrent(dummyDC, 0);
	wglDeleteContext(dummyContext);
	ReleaseDC(dummyWindow, dummyDC);
	DestroyWindow(dummyWindow);
}

OGraphicsEngine::~OGraphicsEngine()
{
}
