#pragma once

#include "Chunginator.h"

namespace CGR
{
	struct KeyCode
	{
		static const int Enter		= GLFW_KEY_ENTER;
		static const int Escape		= GLFW_KEY_ESCAPE;
		static const int KeyDown	= GLFW_KEY_DOWN;
		static const int KeyUp		= GLFW_KEY_UP;
		static const int KeyLeft	= GLFW_KEY_LEFT;
		static const int KeyRight	= GLFW_KEY_RIGHT;
		static const int Zero		= GLFW_KEY_0;
		static const int One		= GLFW_KEY_1;
		static const int Two		= GLFW_KEY_2;
		static const int Three		= GLFW_KEY_3;
		static const int Four		= GLFW_KEY_4;
		static const int Five		= GLFW_KEY_5;
		static const int Six		= GLFW_KEY_6;
		static const int Seven		= GLFW_KEY_7;
		static const int Eight		= GLFW_KEY_8;
		static const int Nine		= GLFW_KEY_9;
		static const int A			= GLFW_KEY_A;
		static const int B			= GLFW_KEY_B;
		static const int C			= GLFW_KEY_C;
		static const int D			= GLFW_KEY_D;
		static const int E			= GLFW_KEY_E;
		static const int F			= GLFW_KEY_F;
		static const int G			= GLFW_KEY_G;
		static const int H			= GLFW_KEY_H;
		static const int I			= GLFW_KEY_I;
		static const int J			= GLFW_KEY_J;
		static const int K			= GLFW_KEY_K;
		static const int L			= GLFW_KEY_L;
		static const int M			= GLFW_KEY_M;
		static const int N			= GLFW_KEY_N;
		static const int O			= GLFW_KEY_O;
		static const int P			= GLFW_KEY_P;
		static const int Q			= GLFW_KEY_Q;
		static const int R			= GLFW_KEY_R;
		static const int S			= GLFW_KEY_S;
		static const int T			= GLFW_KEY_T;
		static const int U			= GLFW_KEY_U;
		static const int V			= GLFW_KEY_V;
		static const int W			= GLFW_KEY_W;
		static const int X			= GLFW_KEY_X;
		static const int Y			= GLFW_KEY_Y;
		static const int Z			= GLFW_KEY_Z;
	};

	struct MouseButton
	{
		static const int LeftButton		= GLFW_MOUSE_BUTTON_LEFT;
		static const int RightButton	= GLFW_MOUSE_BUTTON_RIGHT;
		static const int MiddleButton	= GLFW_MOUSE_BUTTON_MIDDLE;
		static const int LastButton		= GLFW_MOUSE_BUTTON_LAST;
		static const int One			= GLFW_MOUSE_BUTTON_1;
		static const int Two			= GLFW_MOUSE_BUTTON_2;
		static const int Three			= GLFW_MOUSE_BUTTON_3;
		static const int Four			= GLFW_MOUSE_BUTTON_4;
		static const int Five			= GLFW_MOUSE_BUTTON_5;
		static const int Six			= GLFW_MOUSE_BUTTON_6;
		static const int Seven			= GLFW_MOUSE_BUTTON_7;
		static const int Eight			= GLFW_MOUSE_BUTTON_8;
	};

	class Input
	{
	public:
		static int KeyPressed(int keyCode);
		static int MouseButtonPressed(int button);
	};
}