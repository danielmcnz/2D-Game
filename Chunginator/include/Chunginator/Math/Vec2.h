#pragma once

namespace CGR
{
	template<typename T>
	class Vec2
	{
	public:
		union { T x, r; };
		union { T y, g; };

	public:
		Vec2() = default;

		Vec2(T x, T y)
			:
			x(x), y(y)
		{}

		Vec2(const Vec2& copy)
		{
			x = copy.x;
			r = copy.r;
			y = copy.y;
			g = copy.g;
		}

		Vec2& operator=(const Vec2& copy)
		{
			x = copy.x;
			r = copy.r;
			y = copy.y;
			g = copy.g;
		}

		Vec2& operator+=(const Vec2& copy)
		{
			x += copy.x;
			r += copy.r;
			y += copy.y;
			g += copy.g;
		}

		Vec2& operator-=(const Vec2& copy)
		{
			x -= copy.x;
			r -= copy.r;
			y -= copy.y;
			g -= copy.g;
		}

		Vec2& operator*=(const Vec2& copy)
		{
			x *= copy.x;
			r *= copy.r;
			y *= copy.y;
			g *= copy.g;
		}

		Vec2& operator/=(const Vec2& copy)
		{
			x /= copy.x;
			r /= copy.r;
			y /= copy.y;
			g /= copy.g;
		}

		float Magnitude()
		{
			return std::sqrt(x * x + y * y);
		}

		float InverseMagnitude()
		{
			return x * x + y * y;
		}

		Vec2<float>& Normalize()
		{
			float length = Magnitude();

			return { x / length, y / length };
		}
	};

	typedef Vec2<int> Vec2i;
	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;
}