#include "Mathematics/Vector3.h"

#include <cassert>
#include <cmath>

#include "Mathematics/Maths.h"
#include "Mathematics/Vector2.h"
#include "Mathematics/Vector4.h"

namespace BT::Math
{
	float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
	{
		return
		{
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.z
		};
	}

	Vector3::Vector3()
		: x{ 0 }, y{ 0 }, z{ 0 }
	{
	}

	Vector3::Vector3(const float scalar)
		: x{ scalar }, y{ scalar }, z{ scalar }
	{
	}

	Vector3::Vector3(const float x, const float y, const float z)
		: x{ x }, y{ y }, z{ z }
	{
	}

	Vector3::Vector3(const Vector2 other, const float z)
		: x{ other.x }, y{ other.y }, z{ z }
	{
	}

	Vector3::Vector3(const Vector4 other)
		: x{ other.x }, y{ other.y }, z{ other.z }
	{
	}

	void Vector3::Normalize()
	{
		const float magnitude = Magnitude();
		if (Maths::IsNearZero(magnitude))
		{
			x = 0.f;
			y = 0.f;
			z = 0.f;
		}
		else
		{
			x = x / magnitude;
			y = y / magnitude;
			z = z / magnitude;
		}
	}

	Vector3 Vector3::Normalized() const
	{
		const float magnitude = Magnitude();
		return Maths::IsNearZero(magnitude) ?
			Vector3{ 0.f, 0.f, 0.f } :
			Vector3{ x / magnitude, y / magnitude, z / magnitude };
	}

	float Vector3::Magnitude() const
	{
		return sqrtf(MagnitudeSqr());
	}

	float Vector3::MagnitudeSqr() const
	{
		return Dot(*this);
	}

	float Vector3::Dot(const Vector3& other) const
	{
		return Dot(*this, other);
	}

	Vector3 Vector3::Cross(const Vector3& other) const
	{
		return Cross(*this, other);
	}

	bool Vector3::operator==(const Vector3& other) const
	{
		return Maths::CompareFloat(x, other.x) &&
			Maths::CompareFloat(y, other.y) &&
			Maths::CompareFloat(z, other.z);
	}

	bool Vector3::operator!=(const Vector3& other) const
	{
		return !(*this == other);
	}

	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return { x + other.x, y + other.y, z + other.z };
	}

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		if (*this == other)
		{
			return *this;
		}

		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return { x - other.x, y - other.y, z - other.z };
	}

	Vector3& Vector3::operator-=(const Vector3& other)
	{
		if (*this == other)
		{
			return *this;
		}

		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vector3 Vector3::operator*(const float scalar) const
	{
		return { x * scalar, y * scalar, z * scalar };
	}

	Vector3& Vector3::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;

		return *this;
	}

	float Vector3::operator[](const int index) const
	{
		assert(index >= 0 && index < 3);

		return values[index];
	}

#ifdef RAYLIB_SUPPORT_ENABLED
	Vector3::Vector3(const RayVector2 other, const float z)
		: x{ other.x }, y{ other.y }, z{ z }
	{
	}

	Vector3::Vector3(const RayVector3 other)
		: x{ other.x }, y{ other.y }, z{ other.z }
	{
	}

	Vector3::Vector3(const RayVector4 other)
		: x{ other.x }, y{ other.y }, z{ other.z }
	{
	}

	Vector3::operator ::Vector2() const
	{
		return { x, y };
	}

	Vector3::operator ::Vector3() const
	{
		return { x, y, z };
	}

	Vector3::operator ::Vector4() const
	{
		return { x, y, z, 1 };
	}
#endif // RAYLIB_SUPPORT_ENABLED

#ifdef GLM_SUPPORT_ENABLED
	Vector3::Vector3(const GlmVector2 other, const float z)
		: x{ other.x }, y{ other.y }, z{ z }
	{
	}

	Vector3::Vector3(const GlmVector3 other)
		: x{ other.x }, y{ other.y }, z{ other.z }
	{
	}

	Vector3::Vector3(const GlmVector4 other)
		: x{ other.x }, y{ other.y }, z{ other.z }
	{
	}

	Vector3::operator glm::vec<2, float>() const
	{
		return { x, y };
	}

	Vector3::operator glm::vec<3, float>() const
	{
		return { x, y, z };
	}

	Vector3::operator glm::vec<4, float>() const
	{
		return { x, y, z, 1 };
	}
#endif
}
