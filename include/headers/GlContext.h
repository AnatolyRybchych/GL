#ifndef GLCONTEXT_H
#define GLCONTEXT_H

#include<functional>
#include"Init.h"


namespace GL
{
	//each context has own gl objects, textures,shaders, shader programs, everything for GL that initializes not in RAM 
	class GlContext
	{
	public:

		//draw -> drawing function
		GlContext(HDC dc, 
			std::function<void()> initHandler,			//initialize compotents after creating context		
			std::function<void()> drawHandler,									
			std::function<void()> destructHandler,		//on destructor called																	
			PIXELFORMATDESCRIPTOR* pfd = 0);

		//write view into device context
		void Redraw();
		void SetViewPort(int x, int y, int cx, int cy);
		void ChangeDC(HDC newDc);
		//calls changeProc with gl context
		void ChangeContextEnvironment(std::function<void()> changeProc);
		~GlContext();

	protected:
		static bool _isGlatLoaded;

		HDC _deviceContext;
		HGLRC _glContext;

		std::function<void()> _drawHandler;
		std::function<void()> _destructHandler;

		void MakeCurrent();
	};
}
#endif



