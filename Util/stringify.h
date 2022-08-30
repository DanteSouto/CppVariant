#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

template<typename T> inline std::string stringify(const T& x)
{
	std::ostringstream out;
	out << x;
	return out.str();
}
template<> inline std::string stringify<bool>(const bool& x)
{
	return x ? "True" : "False";
}
template<> inline std::string stringify<double>(const double& x)
{
	const int sigdigits = std::numeric_limits<double>::digits10;
	// or perhaps std::numeric_limits<double>::max_digits10 if that is available on your compiler
	std::ostringstream out;
	out << std::setprecision(sigdigits) << x;
	return out.str();
}
template<> inline std::string stringify<float>(const float& x)
{
	const int sigdigits = std::numeric_limits<float>::digits10;
	// or perhaps std::numeric_limits<float>::max_digits10 if that is available on your compiler
	std::ostringstream out;
	out << std::setprecision(sigdigits) << x;
	return out.str();
}
template<> inline std::string stringify<long double>(const long double& x)
{
	const int sigdigits = std::numeric_limits<long double>::digits10;
	// or perhaps std::numeric_limits<long_double>::max_digits10 if that is available on your compiler
	std::ostringstream out;
	out << std::setprecision(sigdigits) << x;
	return out.str();
}