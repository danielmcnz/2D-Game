#pragma once

namespace CGR
{
	template<typename T>
	class Vec4
	{
	public:
		union { T x, r; };
		union { T y, g; };
		union { T z, b; };
		union { T w, a; };

	public:
		Vec4() = default;

		Vec4(T x, T y, T z, T w)
			:
			x(x), y(y), z(z), w(w)
		{}

		Vec4(const Vec4& copy)
		{
			x = copy.x;
			r = copy.r;
			y = copy.y;
			g = copy.g;
			z = copy.z;
			b = copy.b;
			w = copy.w;
			a = copy.a;
		}

		Vec4& operator=(const Vec4& copy)
		{
			x = copy.x;
			r = copy.r;
			y = copy.y;
			g = copy.g;
			z = copy.z;
			b = copy.b;
			w = copy.w;
			a = copy.a;
		}

		Vec4& operator+=(const Vec4& copy)
		{
			x += copy.x;
			r += copy.r;
			y += copy.y;
			g += copy.g;
			z += copy.z;
			b += copy.b;
			w += copy.w;
			a += copy.a;
		}

		Vec4& operator-=(const Vec4& copy)
		{
			x -= copy.x;
			r -= copy.r;
			y -= copy.y;
			g -= copy.g;
			z -= copy.z;
			b -= copy.b;
			w -= copy.w;
			a -= copy.a;
		}

		Vec4& operator*=(const Vec4& copy)
		{
			x *= copy.x;
			r *= copy.r;
			y *= copy.y;
			g *= copy.g;
			z *= copy.z;
			b *= copy.b;
			w *= copy.w;
			a *= copy.a;
		}

		Vec4& operator/=(const Vec4& copy)
		{
			x /= copy.x;
			r /= copy.r;
			y /= copy.y;
			g /= copy.g;
			z /= copy.z;
			b /= copy.b;
			w /= copy.w;
			a /= copy.a;
		}
	};

	typedef Vec4<int> Vec4i;
	typedef Vec4<float> Vec4f;
	typedef Vec4<double> Vec4d;
}