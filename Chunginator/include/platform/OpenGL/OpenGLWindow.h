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

		void SetClearColor(Vec4f clearColor) override;
		void SetVsync(bool enabled) override;
		void SetResizable(bool enabled) override;
		void SetFullScreen() override;
		void SetWindowed() override;
		void SetWindowedBorderless() override;

		bool IsRunning() override;
		void* GetNativeWindow() override { return m_Window; }
	private:
		GLFWwindow* m_Window;

		Renderer* m_Renderer;

		std::string m_Title;
		uint32_t m_Width;
		uint32_t m_Height;
		Vec2i m_WindowPos;

		WindowState m_State;

		bool m_Vsync;
	};
}