#pragma once

namespace CGR
{
	template<typename T>
	class Vec3
	{
	public:
		union { T x, r; };
		union { T y, g; };
		union { T z, b; };

	public:
		Vec3() = default;

		Vec3(T x, T y, T z)
			:
			x(x), y(y), z(z)
		{}

		Vec3(const Vec3& copy)
		{
			x = copy.x;
			r = copy.r;
			y = copy.y;
			g = copy.g;
			z = copy.z;
			b = copy.b;
		}

		Vec3& operator=(const Vec3& copy)
		{
			x = copy.x;
			r = copy.r;
			y = copy.y;
			g = copy.g;
			z = copy.z;
			b = copy.b;
		}

		Vec3& operator+=(const Vec3& copy)
		{
			x += copy.x;
			r += copy.r;
			y += copy.y;
			g += copy.g;
			z += copy.z;
			b += copy.b;
		}

		Vec3& operator-=(const Vec3& copy)
		{
			x -= copy.x;
			r -= copy.r;
			y -= copy.y;
			g -= copy.g;
			z -= copy.z;
			b -= copy.b;
		}

		Vec3& operator*=(const Vec3& copy)
		{
			x *= copy.x;
			r *= copy.r;
			y *= copy.y;
			g *= copy.g;
			z *= copy.z;
			b *= copy.b;
		}

		Vec3& operator/=(const Vec3& copy)
		{
			x /= copy.x;
			r /= copy.r;
			y /= copy.y;
			g /= copy.g;
			z /= copy.z;
			b /= copy.b;
		}
	};

	typedef Vec3<int> Vec3i;
	typedef Vec3<float> Vec3f;
	typedef Vec3<double> Vec3d;
}