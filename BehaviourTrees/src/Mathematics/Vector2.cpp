#include "Mathematics/Vector2.h"

#include <cassert>
#include <cmath>

#include "Mathematics/Maths.h"
#include "Mathematics/Vector3.h"
#include "Mathematics/Vector4.h"

namespace BT::Math
{
	float Vector2::Dot(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	Vector2::Vector2()
		: x{ 0 }, y{ 0 }
	{
	}

	Vector2::Vector2(const float scalar)
		: x{ scalar }, y{ scalar }
	{
	}

	Vector2::Vector2(const float x, const float y)
		: x{ x }, y{ y }
	{
	}

	Vector2::Vector2(const Vector3 other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vector2::Vector2(const Vector4 other)
		: x{ other.x }, y{ other.y }
	{
	}

	void Vector2::Normalize()
	{
		const float magnitude = Magnitude();
		if (Maths::IsNearZero(magnitude))
		{
			x = 0.f;
			y = 0.f;
		}
		else
		{
			x = x / magnitude;
			y = y / magnitude;
		}
	}

	Vector2 Vector2::Normalized() const
	{
		const float magnitude = Magnitude();
		return Maths::IsNearZero(magnitude) ?
			Vector2{ 0.f, 0.f } :
			Vector2{ x / magnitude, y / magnitude };
	}

	float Vector2::Magnitude() const
	{
		return sqrtf(MagnitudeSqr());
	}

	float Vector2::MagnitudeSqr() const
	{
		return Dot(*this);
	}

	float Vector2::Dot(const Vector2& other) const
	{
		return Dot(*this, other);
	}

	bool Vector2::operator==(const Vector2& other) const
	{
		return Maths::CompareFloat(x, other.x) &&
			Maths::CompareFloat(y, other.y);
	}

	bool Vector2::operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}

	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return { x + other.x, y + other.y };
	}

	Vector2& Vector2::operator+=(const Vector2& other)
	{
		if (*this == other)
		{
			return *this;
		}

		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return { x - other.x, y - other.y };
	}

	Vector2& Vector2::operator-=(const Vector2& other)
	{
		if (*this == other)
		{
			return *this;
		}

		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vector2 Vector2::operator*(const float scalar) const
	{
		return { x * scalar, y * scalar };
	}

	Vector2& Vector2::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;

		return *this;
	}

	float Vector2::operator[](const int index) const
	{
		assert(index >= 0 && index < 2);

		return values[index];
	}

#ifdef RAYLIB_SUPPORT_ENABLED
	Vector2::Vector2(const RayVector2 other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vector2::Vector2(const RayVector3 other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vector2::Vector2(const RayVector4 other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vector2::operator ::Vector2() const
	{
		return { x, y };
	}

	Vector2::operator ::Vector3() const
	{
		return { x, y, 0 };
	}

	Vector2::operator ::Vector4() const
	{
		return { x, y, 0, 1 };
	}
#endif // RAYLIB_SUPPORT_ENABLED

#ifdef GLM_SUPPORT_ENABLED
	Vector2::Vector2(const GlmVector2 other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vector2::Vector2(const GlmVector3 other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vector2::Vector2(const GlmVector4 other)
		: x{ other.x }, y{ other.y }
	{
	}

	Vector2::operator glm::vec<2, float>() const
	{
		return { x, y };
	}

	Vector2::operator glm::vec<3, float>() const
	{
		return { x, y, 0 };
	}

	Vector2::operator glm::vec<4, float>() const
	{
		return { x, y, 0, 1 };
	}
#endif

}
