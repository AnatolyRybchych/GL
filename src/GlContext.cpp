#include"../include/headers/GlContext.h"

namespace GL
{
	bool GlContext::_isGlatLoaded = false;

	GlContext::GlContext(HDC dc, 
			std::function<void()> initHandler,			//initialize compotents after creating context		
			std::function<void()> drawHandler,									
			std::function<void()> destructHandler,		//on destructor called																	
			PIXELFORMATDESCRIPTOR* pfd)
	{
		_deviceContext = dc;
		_drawHandler = drawHandler;
		_destructHandler = destructHandler;

		_glContext = GL::__createContext(_deviceContext, pfd);
		MakeCurrent();
		if (!_isGlatLoaded) GL::__loadGlad();
		
		if(initHandler)
			initHandler();
	}

	void GlContext::ChangeContextEnvironment(std::function<void()> changeProc)
	{
		MakeCurrent();
		if(changeProc)
			changeProc();
	}

	void GlContext::SetViewPort(int x, int y, int cx, int cy)
	{
		MakeCurrent();
		glViewport(x,y,cx,cy);
	}

	void GlContext::Redraw()
	{
		MakeCurrent();
		if(_drawHandler)
			_drawHandler();
		SwapBuffers(_deviceContext);
	}

	GlContext::~GlContext()
	{
		if(_destructHandler)
			_destructHandler();
		DeleteDC(_deviceContext);
		wglDeleteContext(_glContext);
	}

	void GlContext::ChangeDC(HDC newDc)
	{
		DeleteDC(_deviceContext);
		_deviceContext = newDc;
		MakeCurrent();
	}

	void GlContext::MakeCurrent()
	{
		GL::__setCurrentContext(_deviceContext, _glContext);
	}
}