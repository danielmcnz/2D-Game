#pragma once

#include "Chunginator.h"
#include "Renderer/Renderer.h"

namespace CGR
{
	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void Clear() = 0;
		virtual void Shutdown() = 0;

		virtual void OnUpdate() = 0;

		virtual void SetClearColor(Vec4f clearColor) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual void SetResizable(bool enabled) = 0;
		virtual void SetFullScreen() = 0;
		virtual void SetBorderless() = 0;

		virtual bool IsRunning() = 0;
		virtual void* GetNativeWindow() = 0;

		static Window* Create(std::string title, uint32_t width, uint32_t height);
	};
}