#pragma once

#include "2D_Game.h"
#include "Core/Input.h"
#include "Core/Layer.h"

namespace CGR
{
	class PerspectiveCamera : public Layer
	{
	public:
		PerspectiveCamera();
		~PerspectiveCamera() override;

		void OnUpdate(float deltaTime) override;
		void OnGuiUpdate() override;
		void OnEvent() override;
		void OnRender() override;

		glm::mat4& GetView() { return m_View; }
		glm::mat4& GetProjection() { return m_Projection; }
		glm::mat4& GetViewProjection() { glm::mat4 vp = m_View * m_Projection; return vp; }

	private:
		glm::mat4 m_View;
		glm::mat4 m_Projection;

		float m_NearPlane;
		float m_FarPlane;
		//float m_Fov;
		float m_CameraSpeed;
		float m_ZoomSpeed;
		Vec3f m_CameraPos;
	};
}