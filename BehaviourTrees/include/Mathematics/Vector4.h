#pragma once

#ifdef RAYLIB_SUPPORT_ENABLED
#include <raylib.h>

typedef Vector2 RayVector2;
typedef Vector3 RayVector3;
typedef Vector4 RayVector4;
#endif

#include "BehaviourTrees.h"

namespace BT::Math
{
	class Vector2;
	class Vector3;

	class DLL Vector4
	{
	public:
		static float Dot(const Vector4& lhs, const Vector4& rhs);
		static Vector4 Cross(const Vector4& lhs, const Vector4& rhs);

	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};

			float values[4];
		};

	public:
		Vector4();
		explicit Vector4(float scalar);
		Vector4(float x, float y, float z, float w);
		Vector4(Vector2 other, float z, float w);
		Vector4(Vector3 other, float w);

	public:
		void Normalize();
		Vector4 Normalized() const;

		float Magnitude() const;
		float MagnitudeSqr() const;

		float Dot(const Vector4& other) const;
		Vector4 Cross(const Vector4& other) const;

	public:
		bool operator==(const Vector4& other) const;
		bool operator!=(const Vector4& other) const;

		Vector4 operator+(const Vector4& other) const;
		Vector4& operator+=(const Vector4& other);

		Vector4 operator-(const Vector4& other) const;
		Vector4& operator-=(const Vector4& other);

		Vector4 operator*(float scalar) const;
		Vector4& operator*=(float scalar);

		float operator[](int index) const;

#ifdef RAYLIB_SUPPORT_ENABLED
	public:
		Vector4(RayVector2 other, float z, float w);
		Vector4(RayVector3 other, float w);
		explicit Vector4(RayVector4 other);

	public:
		explicit operator RayVector2() const;
		explicit operator RayVector3() const;
		explicit operator RayVector4() const;
#endif

	};
}