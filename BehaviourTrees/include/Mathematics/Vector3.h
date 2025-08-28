#pragma once

#ifdef RAYLIB_SUPPORT_ENABLED
#include <raylib.h>

typedef ::Vector2 RayVector2;
typedef ::Vector3 RayVector3;
typedef ::Vector4 RayVector4;
#endif

#ifdef GLM_SUPPORT_ENABLED
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

typedef glm::vec2 GlmVector2;
typedef glm::vec3 GlmVector3;
typedef glm::vec4 GlmVector4;
#endif

#include "BehaviourTrees.h"

namespace BT::Math
{
	class Vector2;
	class Vector4;

	class DLL Vector3
	{
	public:
		static float Dot(const Vector3& lhs, const Vector3& rhs);
		static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);

	public:
		union
		{
			struct
			{
				float x, y, z;
			};

			float values[3];
		};

	public:
		Vector3();
		explicit Vector3(float scalar);
		Vector3(float x, float y, float z);
		Vector3(Vector2 other, float z);
		explicit Vector3(Vector4 other);

	public:
		void Normalize();
		Vector3 Normalized() const;

		float Magnitude() const;
		float MagnitudeSqr() const;

		float Dot(const Vector3& other) const;
		Vector3 Cross(const Vector3& other) const;

	public:
		bool operator==(const Vector3& other) const;
		bool operator!=(const Vector3& other) const;

		Vector3 operator+(const Vector3& other) const;
		Vector3& operator+=(const Vector3& other);

		Vector3 operator-(const Vector3& other) const;
		Vector3& operator-=(const Vector3& other);

		Vector3 operator*(float scalar) const;
		Vector3& operator*=(float scalar);

		float operator[](int index) const;

#ifdef RAYLIB_SUPPORT_ENABLED
	public:
		Vector3(RayVector2 other, float z);
		explicit Vector3(RayVector3 other);
		explicit Vector3(RayVector4 other);

	public:
		explicit operator RayVector2() const;
		explicit operator RayVector3() const;
		explicit operator RayVector4() const;
#endif

#ifdef GLM_SUPPORT_ENABLED
	public:
		Vector3(GlmVector2 other, float z);
		explicit Vector3(GlmVector3 other);
		explicit Vector3(GlmVector4 other);

	public:
		explicit operator GlmVector2() const;
		explicit operator GlmVector3() const;
		explicit operator GlmVector4() const;
#endif

	};
}