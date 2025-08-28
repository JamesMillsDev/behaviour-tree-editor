#include "Mathematics/Maths.h"

#include <cmath>

namespace BT::Math
{
	bool Maths::CompareFloat(const float a, const float b, const float epsilon)
	{
		return std::fabs(a - b) < epsilon;
	}

	bool Maths::IsNearZero(float val, float epsilon)
	{
		return CompareFloat(val, 0.f, epsilon);
	}
}
