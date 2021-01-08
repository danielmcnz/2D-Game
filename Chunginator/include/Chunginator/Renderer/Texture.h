#pragma once

#include "Chunginator.h"

namespace CGR
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void Bind(int slot = 0) = 0;
		virtual void Unbind() = 0;
	};

	class Texture2D : public Texture
	{
	public:
		virtual ~Texture2D() override = default;

		virtual void Bind(int slot = 0) override = 0;
		virtual void Unbind() override = 0;

		virtual void SetData(void* data) = 0;

		static Texture2D* Create(uint32_t width, uint32_t height);
		static Texture2D* Create(std::string texturePath);
	};
}