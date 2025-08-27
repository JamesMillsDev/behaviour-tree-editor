#pragma once

#include <cmath> // For std::fabs
#include <limits> // For std::numeric_limits

#include <raylib.h>

using std::numeric_limits;

namespace BehaviourTree::Editor
{
	inline Color FromHex(int hexCode)
	{
		return Color
		{
			static_cast<unsigned char>(hexCode >> 24 & 0xff),
			static_cast<unsigned char>(hexCode >> 16 & 0xff),
			static_cast<unsigned char>(hexCode >> 8 & 0xff),
			static_cast<unsigned char>(hexCode >> 0 & 0xff)
		};
	}

	inline bool CompareFloat(const float a, const float b, const float epsilon = numeric_limits<float>::epsilon())
	{
		return std::fabs(a - b) < epsilon;
	}
}