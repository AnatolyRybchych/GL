#include "../include/headers/Init.h"


void GL::__loadGlad()
{
	gladLoadGL();
}

HGLRC GL::__createContext(HDC dc, PIXELFORMATDESCRIPTOR* pixelFormat)
{
	PIXELFORMATDESCRIPTOR pfd;
	if (!pixelFormat)
	{
		pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
		32,                   // Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                   // Number of bits for the depthbuffer
		8,                    // Number of bits for the stencilbuffer
		0,                    // Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
		};
	}
	else
	{
		pfd = *pixelFormat;
	}

	SetPixelFormat(dc, ChoosePixelFormat(dc, &pfd), &pfd);
	return wglCreateContext(dc);
}

void GL::__setCurrentContext(HDC dc, HGLRC GLContext)
{
	wglMakeCurrent(dc, GLContext);
}