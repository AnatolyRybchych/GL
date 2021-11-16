#include"../include/headers/GlContext.h"

namespace GL
{
	bool GlContext::_isGlatLoaded = false;

	GlContext::GlContext(HDC dc,
		std::function<void()> beforeDrawHandler,	//beforeDrawHandler() -> drawHandler() -> afterDrawingHandler()   is drawing procedure		,can be 0 to ignore
		std::function<void()> drawHandler,			//beforeDrawHandler() -> drawHandler() -> afterDrawingHandler()   is drawing procedure		,can be 0 to ignore
		std::function<void()> afterDrawingHandler,	//beforeDrawHandler() -> drawHandler() -> afterDrawingHandler()   is drawing procedure		,can be 0 to ignore
		std::function<void()> initHandler,			//initialize compotents after creating context												,can be 0 to ignore
		std::function<void()> destructHandler,		//on destructor called																		,can be 0 to ignore
		PIXELFORMATDESCRIPTOR* pfd)
	{
		_deviceContext = dc;
		_beforedrawHandler = beforeDrawHandler;
		_drawHandler = drawHandler;
		_afterdrawHandler = afterDrawingHandler;
		_destructHandler = destructHandler;

		_glContext = GL::__createContext(_deviceContext, pfd);
		MakeCurrent();
		if (!_isGlatLoaded) GL::__loadGlad();
		
		initHandler();
	}

	void GlContext::ChangeContextEnvironment(std::function<void()> changeProc)
	{
		MakeCurrent();
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
		_beforedrawHandler();
		_drawHandler();
		_afterdrawHandler();
		SwapBuffers(_deviceContext);
	}

	GlContext::~GlContext()
	{
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