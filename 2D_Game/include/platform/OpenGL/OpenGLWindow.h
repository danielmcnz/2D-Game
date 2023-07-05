#pragma once

#include "Core/Window.h"

namespace CGR
{
	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(std::string title, uint32_t width, uint32_t height);
		~OpenGLWindow() override;

		void Clear() override;
		void Shutdown() override;

		void OnUpdate() override;
		void OnEvent() override;

		void SetClearColor(Vec4f clearColor) override;
		void SetVsync(bool enabled) override;
		void SetResizable(bool enabled) override;
		void SetIcon(std::string iconPath) override;

		bool IsFullScreen() override { return m_State == WindowState::Fullscreen; };
		void SetFullScreen() override;
		void SetWindowed() override;
		void SetWindowed(uint32_t x_Pos, uint32_t y_Pos, uint32_t width, uint32_t height) override;
		void SetWindowedBorderless() override;
		void SetWindowedFullscreen() override;

		uint32_t GetWidth() override { return m_WindowSize.x; }
		uint32_t GetHeight() override { return m_WindowSize.y; }

		bool IsRunning() override;
		void* GetNativeWindow() override { return m_Window; }

	private:
		GLFWwindow* m_Window;

		Renderer* m_Renderer;

		std::string m_Title;
		Vec2i m_WindowSize;
		Vec2i m_WindowedWindowSize;
		Vec2i m_WindowPos;

		WindowState m_State;

		bool m_Vsync;
	};
}