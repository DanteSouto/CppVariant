#pragma once
#include <iostream>
#include <vector>
#include <format>
#include <sstream>
#include <iomanip>

//#include <iostream>
//#include <format>
//#include <sstream>
//#include <iomanip>
#include <string>
#include <limits>
#include <time.h>
//#include <variant>
//#include "../BitConverter/BitConverter.h"


namespace lsvbs
{
	
	using byte = unsigned char;
	using bytes = std::vector<byte>;

	enum DATA_TYPE
	{
		UNDEFINED,
		BOOLEAN,
		INT,
		LONG,
		DOUBLE,
		STRING,
		DATETIME,
		ARRAY,
		ERROR
	};

	static const char* DATA_TYPE_STR[] =
	{ 
		"Undefined",
		"Boolean",
		"Integer",
		"Long",
		"Double",
		"String",
		"DateAndTime",
		"Array",
		"Error"
	};

	enum class ACCESSOR
	{
		PUBLIC,
		PRIVATE,
		BYREF,
		BYVAL
	};
}

