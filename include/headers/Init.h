#ifndef INIT_H
#define INIT_H

#include "opengl.h"

namespace GL
{

	void __loadGlad();
	HGLRC __createContext(HDC dc, PIXELFORMATDESCRIPTOR* pixelFormat = NULL);
	void __setCurrentContext(HDC dc, HGLRC GLContext);


}
#endif