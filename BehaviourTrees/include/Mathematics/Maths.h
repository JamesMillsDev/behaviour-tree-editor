#pragma once

#include <limits>

#include "BehaviourTrees.h"

using std::numeric_limits;

namespace BT::Math
{
	class DLL Maths
	{
	public:
		static bool CompareFloat(float a, float b, float epsilon = numeric_limits<float>::epsilon());
		static bool IsNearZero(float val, float epsilon = numeric_limits<float>::epsilon());

	};
}