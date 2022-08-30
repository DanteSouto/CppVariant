#pragma once

#include "../Util/globais.h"
#include "../BitConverter/BitConverter.h"

namespace lsvbs
{
    class Variant
    {
    public:

        int Address;
        ACCESSOR Accessor;
        
        Variant operator[](int index) 
        {
            data dnew = myarray[index];
            Variant vnew(dnew);
            return vnew;
        }

        Variant* operator=(Variant value);
        Variant* operator=(data value);
        Variant* operator=(bool value);
        Variant* operator=(int value);
        Variant* operator=(long value);
        Variant* operator=(double value);
        Variant* operator=(std::string value);
        Variant* operator=(std::time_t value);
        
        Variant operator+(Variant& variant);
        Variant operator+(int value);
        Variant operator+(long value);
        Variant operator+(double value);
        Variant operator+(std::string& value);
        Variant operator+(const char* value);

        Variant operator-(Variant& variant);
        Variant operator-(int value);
        Variant operator-(long value);
        Variant operator-(double value);
        
        Variant operator*(Variant& variant);
        Variant operator*(int value);
        Variant operator*(long value);
        Variant operator*(double value);
        
        Variant operator/(Variant& variant);
        Variant operator/(int value);
        Variant operator/(long value);
        Variant operator/(double value);

        Variant operator%(Variant& variant);
        Variant operator%(int value);
        Variant operator%(long value);

        Variant operator<(Variant& variant);
        Variant operator<(int value);
        Variant operator<(long value);
        Variant operator<(double value);
        
        Variant operator<=(Variant& variant);
        Variant operator<=(int value);
        Variant operator<=(long value);
        Variant operator<=(double value);
        
        Variant operator>(Variant& variant);
        Variant operator>(int value);
        Variant operator>(long value);
        Variant operator>(double value);
        
        Variant operator>=(Variant& variant);
        Variant operator>=(int value);
        Variant operator>=(long value);
        Variant operator>=(double value);
        
        Variant operator==(Variant& variant);
        Variant operator==(bool value);
        Variant operator==(int value);
        Variant operator==(long value);
        Variant operator==(double value);
        Variant operator==(std::string value);
        
        Variant operator&&(Variant& variant);   // and lógico
        Variant operator&&(bool value);
        Variant operator&&(int value);
        Variant operator&&(long value);
        Variant operator&&(double value);
        
        Variant operator^(Variant& variant);    // or exclusivo
        Variant operator^(bool value);
        Variant operator^(int value);
        Variant operator^(long value);
        
        Variant operator||(Variant& variant);    // or lógico
        Variant operator||(bool value);
        Variant operator||(int value);
        Variant operator||(long value);

        template <typename T> T GetT()
        {
            T& myVar;
            switch (mydata.type)
            {
            case DATA_TYPE::ARRAY:
                myVar = mydata;
                break;
            case DATA_TYPE::BOOLEAN:
            {
                myVar = BitConverter::ToBool(mydata.buffer);
                break;
            }
            case DATA_TYPE::DATETIME:
            {
                myVar = BitConverter::ToDateTime(mydata.buffer);
                break;
            }
            case DATA_TYPE::DOUBLE:
            {
                myVar = BitConverter::ToDouble(mydata.buffer);
                break;
            }
            case DATA_TYPE::ERROR:
                throw std::invalid_argument("Error data type");
            case DATA_TYPE::INT:
            {
                myVar = BitConverter::ToInt(mydata.buffer);
                break;
            }
            case DATA_TYPE::LONG:
            {
                myVar = BitConverter::ToLong(mydata.buffer);
                break;
            }
            case DATA_TYPE::STRING:
            {
                myVar = BitConverter::ToString(mydata.buffer);
                break;
            }
            case DATA_TYPE::UNDEFINED:
                throw std::invalid_argument("Undefined data type");
            }
            return myVar;
        }

        std::string ToString() const
        {
            return mydata.ToString();
        }

        Variant()
        {
            mydata.type = DATA_TYPE::UNDEFINED;
            Address = 0;
            Accessor = ACCESSOR::PUBLIC;
        }
        
        Variant(DATA_TYPE type)
        {
            mydata.type = type;
            Address = 0;
            Accessor = ACCESSOR::PUBLIC;
        }
        
        template<typename T> Variant(T& value)
        {
            Set(value);
            Accessor = ACCESSOR::PUBLIC;
        }

        ~Variant()
        {
            myarray.~vector();
            //
        }

        data Data()
        {
            return mydata;
        }

        bytes BinaryData()
        {
            return mydata.buffer;
        }
        
        DATA_TYPE Type()
        {
            return mydata.type;
        }

        std::string TypeName()
        {
            return DATA_TYPE_STR[mydata.type];
        }

        template<typename T> void Set(T& value)
        {
            if (std::is_same_v<T, Variant>)
            {
                return SetValue_part<T>(value);
            }
            else if (std::is_same_v<T, data>)
            {
                return SetValue_part<T>(value);
            }
            else if (std::is_same_v<T, bool>)
            {
                return SetValue_part<T>(value);
            }
            else if (std::is_same_v<T, int>)
            {
                return SetValue_part<T>(value);
            }
            else if (std::is_same_v<T, long>)
            {
                return SetValue_part<T>(value);
            }
            else if (std::is_same_v<T, double>)
            {
                return SetValue_part<T>(value);
            }
            else if (std::is_same_v<T, std::string>)
            {
                return SetValue_part<T>(value);
            }
            else if (std::is_same_v<T, std::time_t>)
            {
                return SetValue_part<T>(value);
            }
        }

        Variant GetV()
        {
            Variant tmp(mydata);
            tmp.Set(mydata);
            tmp.Accessor = Accessor;
            return tmp;
        }

        template<typename T> T Get()
        {
            if (std::is_same_v<T, Variant>)
            {
                return GetValue_part<T>();
            }
            else if(mydata.type != DATA_TYPE::ARRAY)
            {
                if (std::is_same_v<T, data>)
                {
                    return GetValue_part<T>();
                }
                else if (std::is_same_v<T, bool>)
                {
                    return GetValue_part<T>();
                }
                else if (std::is_same_v<T, int>)
                {
                    return GetValue_part<T>();
                }
                else if (std::is_same_v<T, long>)
                {
                    return GetValue_part<T>();
                }
                else if (std::is_same_v<T, double>)
                {
                    return GetValue_part<T>();
                }
                else if (std::is_same_v<T, std::string>)
                {
                    return GetValue_part<T>();
                }
                else if (std::is_same_v<T, std::time_t >)
                {
                    return GetValue_part<T>();
                }
                else
                {
                    throw std::invalid_argument("Not implemented...");
                }
            }
            else
            { 
                throw std::invalid_argument("It's not allowed on array...");
            }
        }

        template<typename T> void Push(const T& value)
        {
            if (mydata.type == DATA_TYPE::UNDEFINED)
            {
                mydata.type = DATA_TYPE::ARRAY;
            }

            if (mydata.type = DATA_TYPE::ARRAY)
            {
                Push_part(value);
            }
            else
            {
                throw std::invalid_argument("It's not an array...");
            }
        }

        template<typename T> void Insert(const int& index, const T& value)
        {
            if (mydata.type == DATA_TYPE::UNDEFINED)
            {
                mydata.type = DATA_TYPE::ARRAY;
            }

            if (mydata.type = DATA_TYPE::ARRAY)
            {
                Insert_part(index, value);
            }
            else
            {
                throw std::invalid_argument("It's not an array...");
            }
        }
        
        template<typename T> void Pull(const T& value)
        {
            if (mydata.type == DATA_TYPE::UNDEFINED)
            {
                mydata.type = DATA_TYPE::ARRAY;
            }

            if (mydata.type = DATA_TYPE::ARRAY)
            {
                Pull_part(value);
            }
            else
            {
                throw std::invalid_argument("It's not an array...");
            }
        }
        
        void Pop()
        {
            if (mydata.type == DATA_TYPE::UNDEFINED)
            {
                mydata.type = DATA_TYPE::ARRAY;
            }

            if (mydata.type = DATA_TYPE::ARRAY)
            {
                myarray.pop_back();
            }
            else
            {
                throw std::invalid_argument("It's not an array...");
            }
        }

        void Remove(int& index)
        {
            if (mydata.type == DATA_TYPE::UNDEFINED)
            {
                mydata.type = DATA_TYPE::ARRAY;
            }

            if (mydata.type = DATA_TYPE::ARRAY)
            {
                std::vector<data> mynewarray;
                for (int i = 0; i < myarray.size(); i++)
                {
                    if (i != index)
                    {
                        mynewarray.push_back(myarray[i]);
                    }
                }
                myarray = mynewarray;
                mynewarray.~vector();
            }
            else
            {
                throw std::invalid_argument("It's not an array...");
            }
        }

        std::size_t Count()
        {
            if (mydata.type != DATA_TYPE::ARRAY)
            {
                throw std::invalid_argument("It's not an array");
            }
            else
            {
                return myarray.size();
            }
        }

        std::size_t Length() { return Count(); }

    private:
        data mydata;
        std::vector<data> myarray;
        
        template<typename T> inline void SetValue_part(T& value)
        {
            //
        }
        template<> inline void SetValue_part<Variant>(Variant& value)
        {
            data dnew = value.Data();
            mydata = dnew;
        }

        template<> inline void SetValue_part<data>(data& value)
        {
            mydata = value;
        }

        template<> inline void SetValue_part<bool>(bool& value)
        {
            mydata = BitConverter::GetBytes(value);
        }
        
        template<> inline void SetValue_part<int>(int& value)
        {
            mydata = BitConverter::GetBytes(value);
        }
        
        template<> inline void SetValue_part<long>(long& value)
        {
            mydata = BitConverter::GetBytes(value);
        }

        template<> inline void SetValue_part<double>(double& value)
        {
            mydata = BitConverter::GetBytes(value);
        }

        template<> inline void SetValue_part<std::string>(std::string& value)
        {
            mydata = BitConverter::GetBytes(value);
        }

        template<> inline void SetValue_part<std::time_t>(std::time_t& value)
        {
            mydata = BitConverter::GetBytes(value);
        }


        template<typename T> const inline T GetValue_part()
        {
            // nada
        }

        template<> inline const Variant GetValue_part()
        {
            Variant tmp(mydata);
            return tmp;
        }

        template<> inline const data GetValue_part()
        {
            return mydata;
        }

        template<> inline const bool GetValue_part()
        {
            return BitConverter::ToBool(mydata.buffer);
        }
        
        template<> inline const int GetValue_part()
        {
            return BitConverter::ToInt(mydata.buffer);
        }
        
        template<> inline const long GetValue_part()
        {
            return BitConverter::ToLong(mydata.buffer);
        }

        template<> inline const double GetValue_part()
        {
            return BitConverter::ToDouble(mydata.buffer);
        }

        template<> inline const std::string GetValue_part()
        {
            return BitConverter::ToString(mydata.buffer);
        }

        template<> inline const std::time_t GetValue_part()
        {
            return BitConverter::ToDateTime(mydata.buffer);
        }

        template<typename T> inline void Push_part(T value)
        {
            if (std::is_same_v<T, Variant>)
            {
                Push_part<T>(value);
            }
            else if (std::is_same_v<T, data>)
            {
                Push_part<T>(value);
            }
            else if (std::is_same_v<T, bool>)
            {
                Push_part<T>(value);
            }
            else if (std::is_same_v<T, int>)
            {
                Push_part<int>(value);
            }
            else if (std::is_same_v<T, long>)
            {
                Push_part<T>(value);
            }
            else if (std::is_same_v<T, double>)
            {
                Push_part<T>(value);
            }
            else if (std::is_same_v<T, std::string>)
            {
                Push_part<T>(value);
            }
            else if (std::is_same_v<T, std::time_t>)
            {
                Push_part<T>(value);
            }
            else
            {
                throw std::invalid_argument("Not implemented...");
            }
        }

        template<> inline void Push_part<Variant>(Variant value)
        {
            data tmp_data = value.Data();
            myarray.push_back(tmp_data);
        }

        template<> inline void Push_part<data>(data value)
        {
            data tmp_data = value;
            myarray.push_back(tmp_data);
        }

        template<> inline void Push_part<bool>(bool value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            myarray.push_back(tmp_data);
        }
        
        template<> inline void Push_part<int>(int value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            myarray.push_back(tmp_data);
        }
        
        template<> inline void Push_part<long>(long value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            myarray.push_back(tmp_data);
        }

        template<> inline void Push_part<double>(double value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            myarray.push_back(tmp_data);
        }

        template<> inline void Push_part<std::string>(std::string value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            myarray.push_back(tmp_data);
        }

        template<> inline void Push_part<std::time_t>(std::time_t value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            myarray.push_back(tmp_data);
        }
        
        template<typename T> inline void Pull_part(T value)
        {
            if (std::is_same_v<T, Variant>)
            {
                Pull_part<T>(value);
            }
            else if (std::is_same_v<T, data>)
            {
                Pull_part<T>(value);
            }
            else if (std::is_same_v<T, bool>)
            {
                Pull_part<T>(value);
            }
            else if (std::is_same_v<T, int>)
            {
                Pull_part<int>(value);
            }
            else if (std::is_same_v<T, long>)
            {
                Pull_part<T>(value);
            }
            else if (std::is_same_v<T, double>)
            {
                Pull_part<T>(value);
            }
            else if (std::is_same_v<T, std::string>)
            {
                Pull_part<T>(value);
            }
            else if (std::is_same_v<T, std::time_t>)
            {
                Pull_part<T>(value);
            }
            else
            {
                throw std::invalid_argument("Not implemented...");
            }
        }

        template<> inline void Pull_part<Variant>(Variant value)
        {
            data tmp_data = value.Data();
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<> inline void Pull_part<data>(data value)
        {
            data tmp_data = value;
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<> inline void Pull_part<bool>(bool value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<> inline void Pull_part<int>(int value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<> inline void Pull_part<long>(long value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<> inline void Pull_part<double>(double value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<> inline void Pull_part<std::string>(std::string value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<> inline void Pull_part<std::time_t>(std::time_t value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::size_t pos = myarray.size() - 1;
            myarray[pos] = tmp_data;
        }

        template<typename T> inline void Insert_part(int pos,T value)
        {
            if (std::is_same_v<T, Variant>)
            {
                Insert_part<T>(pos, value);
            }
            else if (std::is_same_v<T, data>)
            {
                Insert_part<T>(pos, value);
            }
            else if (std::is_same_v<T, bool>)
            {
                Insert_part<T>(pos, value);
            }
            else if (std::is_same_v<T, int>)
            {
                Insert_part<int>(pos, value);
            }
            else if (std::is_same_v<T, long>)
            {
                Insert_part<T>(pos, value);
            }
            else if (std::is_same_v<T, double>)
            {
                Insert_part<T>(pos, value);
            }
            else if (std::is_same_v<T, std::string>)
            {
                Insert_part<T>(pos, value);
            }
            else if (std::is_same_v<T, std::time_t>)
            {
                Insert_part<T>(pos, value);
            }
            else
            {
                throw std::invalid_argument("Not implemented...");
            }
        }

        template<> inline void Insert_part<Variant>(int pos, Variant value)
        {
            data tmp_data = value.Data();
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }

        template<> inline void Insert_part<data>(int pos, data value)
        {
            data tmp_data = value;
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }

        template<> inline void Insert_part<bool>(int pos, bool value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }

        template<> inline void Insert_part<int>(int pos, int value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }

        template<> inline void Insert_part<long>(int pos, long value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }

        template<> inline void Insert_part<double>(int pos, double value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }

        template<> inline void Insert_part<std::string>(int pos, std::string value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }

        template<> inline void Insert_part<std::time_t>(int pos, std::time_t value)
        {
            data tmp_data = BitConverter::GetBytes(value);
            std::vector<data> mynewarray;
            for (int i = 0; i < myarray.size(); i++)
            {
                if (i == pos)
                {
                    mynewarray.push_back(tmp_data);
                }
                mynewarray.push_back(myarray[i]);
            }
            myarray = mynewarray;
        }
    };
}
