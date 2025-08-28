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
	class Vector3;
	class Vector4;

	class DLL Vector2
	{
	public:
		static float Dot(const Vector2& lhs, const Vector2& rhs);

	public:
		union
		{
			struct
			{
				float x, y;
			};

			float values[2];
		};

	public:
		Vector2();
		explicit Vector2(float scalar);
		Vector2(float x, float y);
		explicit Vector2(Vector3 other);
		explicit Vector2(Vector4 other);

	public:
		void Normalize();
		Vector2 Normalized() const;

		float Magnitude() const;
		float MagnitudeSqr() const;

		float Dot(const Vector2& other) const;

	public:
		bool operator==(const Vector2& other) const;
		bool operator!=(const Vector2& other) const;

		Vector2 operator+(const Vector2& other) const;
		Vector2& operator+=(const Vector2& other);

		Vector2 operator-(const Vector2& other) const;
		Vector2& operator-=(const Vector2& other);

		Vector2 operator*(float scalar) const;
		Vector2& operator*=(float scalar);

		float operator[](int index) const;

#ifdef RAYLIB_SUPPORT_ENABLED
	public:
		explicit Vector2(RayVector2 other);
		explicit Vector2(RayVector3 other);
		explicit Vector2(RayVector4 other);

	public:
		explicit operator RayVector2() const;
		explicit operator RayVector3() const;
		explicit operator RayVector4() const;
#endif

#ifdef GLM_SUPPORT_ENABLED
	public:
		explicit Vector2(GlmVector2 other);
		explicit Vector2(GlmVector3 other);
		explicit Vector2(GlmVector4 other);

	public:
		explicit operator GlmVector2() const;
		explicit operator GlmVector3() const;
		explicit operator GlmVector4() const;
#endif

	};
}