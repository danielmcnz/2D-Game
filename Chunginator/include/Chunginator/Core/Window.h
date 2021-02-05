#pragma once

#include "Chunginator.h"
#include "Renderer/Renderer.h"
#include "Events/Event.h"

namespace CGR
{
	enum class WindowState
	{
		Windowed,
		Fullscreen,
		WindowedBorderless
	};

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void Clear() = 0;
		virtual void Shutdown() = 0;

		virtual void OnUpdate() = 0;
		virtual void OnEvent() = 0;

		virtual void SetClearColor(Vec4f clearColor) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual void SetResizable(bool enabled) = 0;
		virtual void SetIcon(std::string iconPath) = 0;

		virtual bool IsFullScreen() = 0;
		virtual void SetFullScreen() = 0;
		virtual void SetWindowed() = 0;
		virtual void SetWindowed(uint32_t x_Pos, uint32_t y_Pos, uint32_t width, uint32_t height) = 0;
		virtual void SetWindowedBorderless() = 0;
		virtual void SetWindowedFullscreen() = 0;

		virtual uint32_t GetWidth() = 0;
		virtual uint32_t GetHeight() = 0;

		virtual bool IsRunning() = 0;
		virtual void* GetNativeWindow() = 0;

		static Window* Create(std::string title, uint32_t width, uint32_t height);
	};
}