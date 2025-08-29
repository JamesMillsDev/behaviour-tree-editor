#pragma once

#ifdef DLL_EXPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

namespace BT
{
	enum class ENodeResult : unsigned char
	{
		Failed,
		Succeeded,
		Pending
	};
}