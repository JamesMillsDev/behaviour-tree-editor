#include "Mathematics/Vector4.h"

#include <cassert>
#include <cmath>

#include "Mathematics/Maths.h"
#include "Mathematics/Vector2.h"
#include "Mathematics/Vector3.h"

namespace BT::Math
{
	float Vector4::Dot(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	Vector4 Vector4::Cross(const Vector4& lhs, const Vector4& rhs)
	{
		return
		{
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.z,
			0.f
		};
	}

	Vector4::Vector4()
		: x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 }
	{
	}

	Vector4::Vector4(const float scalar)
		: x{ scalar }, y{ scalar }, z{ scalar }, w{ scalar }
	{
	}

	Vector4::Vector4(const float x, const float y, const float z, const float w)
		: x{ x }, y{ y }, z{ z }, w{ w }
	{
	}

	Vector4::Vector4(const Vector2 other, const float z, const float w)
		: x{ other.x }, y{ other.y }, z{ z }, w{ w }
	{
	}

	Vector4::Vector4(const Vector3 other, const float w)
		: x{ other.x }, y{ other.y }, z{ other.z }, w{ w }
	{
	}

	void Vector4::Normalize()
	{
		const float magnitude = Magnitude();
		if (Maths::IsNearZero(magnitude))
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
			w = 0.f;
		}
		else
		{
			x = x / magnitude;
			y = y / magnitude;
			z = z / magnitude;
			w = w / magnitude;
		}
	}

	Vector4 Vector4::Normalized() const
	{
		const float magnitude = Magnitude();
		return Maths::IsNearZero(magnitude) ?
			Vector4{ 0.f, 0.f, 0.f, 0.f } :
			Vector4{ x / magnitude, y / magnitude, z / magnitude, w / magnitude };
	}

	float Vector4::Magnitude() const
	{
		return sqrtf(MagnitudeSqr());
	}

	float Vector4::MagnitudeSqr() const
	{
		return Dot(*this);
	}

	float Vector4::Dot(const Vector4& other) const
	{
		return Dot(*this, other);
	}

	Vector4 Vector4::Cross(const Vector4& other) const
	{
		return Cross(*this, other);
	}

	bool Vector4::operator==(const Vector4& other) const
	{
		return Maths::CompareFloat(x, other.x) &&
			Maths::CompareFloat(y, other.y) &&
			Maths::CompareFloat(z, other.z) &&
			Maths::CompareFloat(w, other.w);
	}

	bool Vector4::operator!=(const Vector4& other) const
	{
		return !(*this == other);
	}

	Vector4 Vector4::operator+(const Vector4& other) const
	{
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}

	Vector4& Vector4::operator+=(const Vector4& other)
	{
		if (*this == other)
		{
			return *this;
		}

		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	Vector4 Vector4::operator-(const Vector4& other) const
	{
		return { x - other.x, y - other.y, z - other.z, w - other.w };
	}

	Vector4& Vector4::operator-=(const Vector4& other)
	{
		if (*this == other)
		{
			return *this;
		}

		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}

	Vector4 Vector4::operator*(const float scalar) const
	{
		return { x * scalar, y * scalar, z * scalar, w * scalar };
	}

	Vector4& Vector4::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;

		return *this;
	}

	float Vector4::operator[](const int index) const
	{
		assert(index >= 0 && index < 4);

		return values[index];
	}

#ifdef RAYLIB_SUPPORT_ENABLED
	Vector4::Vector4(const RayVector2 other, const float z, const float w)
		: x{ other.x }, y{ other.y }, z{ z }, w{ w }
	{
	}

	Vector4::Vector4(const RayVector3 other, const float w)
		: x{ other.x }, y{ other.y }, z{ other.z }, w{ w }
	{
	}

	Vector4::Vector4(const RayVector4 other)
		: x{ other.x }, y{ other.y }, z{ other.z }, w{ other.w }
	{
	}

	Vector4::operator ::Vector2() const
	{
		return { x, y };
	}

	Vector4::operator ::Vector3() const
	{
		return { x, y, z };
	}

	Vector4::operator ::Vector4() const
	{
		return { x, y, z, w };
	}
#endif // RAYLIB_SUPPORT_ENABLED

#ifdef GLM_SUPPORT_ENABLED
	Vector4::Vector4(const GlmVector2 other, const float z, const float w)
		: x{ other.x }, y{ other.y }, z{ z }, w{ w }
	{
	}

	Vector4::Vector4(const GlmVector3 other, const float w)
		: x{ other.x }, y{ other.y }, z{ other.z }, w{ w }
	{
	}

	Vector4::Vector4(const GlmVector4 other)
		: x{ other.x }, y{ other.y }, z{ other.z }, w{ other.w }
	{
	}

	Vector4::operator glm::vec<2, float>() const
	{
		return { x, y };
	}

	Vector4::operator glm::vec<3, float>() const
	{
		return { x, y, z };
	}

	Vector4::operator glm::vec<4, float>() const
	{
		return { x, y, z, w };
	}
#endif
}
