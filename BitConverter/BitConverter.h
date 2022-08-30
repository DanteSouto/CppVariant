#pragma once
#include "../Util/globais.h"
#include "../Util/data.h"
#include <iostream>

namespace lsvbs 
{
	class BitConverter
	{
	
	public:
		static long ToBool(bytes value);
		static long ToInt(bytes value);
		static long ToLong(bytes value);
		static double ToDouble(bytes value);
		static std::time_t ToDateTime(bytes value);
		static std::string ToString(bytes value);

		static data GetBytes(bool value);
		static data GetBytes(int value);
		static data GetBytes(long value);
		static data GetBytes(double value);
		static data GetBytes(std::time_t value);
		static data GetBytes(std::string value);
	
	private:
		// Disallow creating an instance of this object
		BitConverter() {}
	};
}


