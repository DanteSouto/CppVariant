#include "BitConverter.h"

namespace lsvbs
{
	data BitConverter::GetBytes(bool value)
	{
		byte* byteArray = reinterpret_cast<byte*>(&value);

		int sz = sizeof(byteArray);

		data mydata;
		for (int i = 0; i < sz; i++) {
			mydata.buffer.push_back(byteArray[i]);
		}
		mydata.type = DATA_TYPE::BOOLEAN;
		return mydata;
	}
	
	data BitConverter::GetBytes(int value)
	{
		byte* byteArray = reinterpret_cast<byte*>(&value);

		int sz = sizeof(byteArray);

		data mydata;
		for (int i = 0; i < sz; i++) {
			mydata.buffer.push_back(byteArray[i]);
		}
		mydata.type = DATA_TYPE::INT;
		return mydata;
	}
	
	data BitConverter::GetBytes(long value)
	{
		byte* byteArray = reinterpret_cast<byte*>(&value);

		int sz = sizeof(byteArray);

		data mydata;
		for (int i = 0; i < sz; i++) {
			mydata.buffer.push_back(byteArray[i]);
		}
		mydata.type = DATA_TYPE::LONG;
		return mydata;
	}

	data BitConverter::GetBytes(double value)
	{
		byte* byteArray = reinterpret_cast<byte*>(&value);

		int sz = sizeof(byteArray);

		data mydata;
		for (int i = 0; i < sz; i++) {
			mydata.buffer.push_back(byteArray[i]);
		}
		mydata.type = DATA_TYPE::DOUBLE;
		return mydata;
	}

	data BitConverter::GetBytes(std::time_t value)
	{
		byte* byteArray = reinterpret_cast<byte*>(&value);

		int sz = sizeof(byteArray);

		data mydata;
		std::vector<byte> vec;
		for (int i = 0; i < sz; i++) {
			mydata.buffer.push_back(byteArray[i]);
		}
		mydata.type = DATA_TYPE::DATETIME;
		return mydata;
	}

	data BitConverter::GetBytes(std::string value)
	{
		std::size_t sz = value.length();
		data mydata;
		for (int i = 0; i < sz; i++) {
			mydata.buffer.push_back(value[i]);
		}
		mydata.type = DATA_TYPE::STRING;
		return mydata;
	}

	long BitConverter::ToBool(bytes value)
	{
		return *reinterpret_cast<bool*>(value.data());
	}
	
	long BitConverter::ToInt(bytes value)
	{
		return *reinterpret_cast<int*>(value.data());
	}
	
	long BitConverter::ToLong(bytes value)
	{
		return *reinterpret_cast<long*>(value.data());
	}

	double BitConverter::ToDouble(bytes value)
	{
		return *reinterpret_cast<double*>(value.data());
	}

	std::time_t BitConverter::ToDateTime(bytes value)
	{
		return *reinterpret_cast<std::time_t*>(value.data());
	}

	std::string BitConverter::ToString(bytes value)
	{
		std::string ret(value.begin(), value.end());
		return ret;
	}
}

