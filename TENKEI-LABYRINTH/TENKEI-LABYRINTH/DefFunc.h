#pragma once
#include <filesystem>

#include "JoyPad.h"
#include "Keyboard.h"

#define WND_HEIGHT	1080
#define WND_WIDTH	1920
#define FONT_SIZE	32
#define STR(var) #var

#define RELEASE(x)				\
{								\
	if((x) != nullptr)			\
	{							\
		delete (x);				\
		(x) = nullptr;			\
	}							\
}								\

#define ARY_SIZE(ary)			\
{								\
	sizeof(ary) / sizeof(ary[0])\
}								\

using namespace std;
namespace fs = filesystem;

inline namespace Func
{
	template
	<
		typename TYPE, 
		size_t SIZE
	>
	size_t ary_leng(const TYPE (&)[SIZE])
	{
		return SIZE;
	}
}