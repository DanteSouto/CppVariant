#include "Variant.h"

namespace lsvbs
{
    data::operator bool() const { return BitConverter::ToBool(buffer); }
    data::operator int() const { return BitConverter::ToInt(buffer); }
    data::operator long() const { return BitConverter::ToLong(buffer); }
    data::operator double() const { return BitConverter::ToDouble(buffer); }
    data::operator std::string() const { return ToString(); }
    data::operator std::time_t() const { return BitConverter::ToDateTime(buffer); }

    std::string data::ToString() const
    {
        switch (type)
        {
        case DATA_TYPE::ARRAY:
            return "Array";
        case DATA_TYPE::BOOLEAN:
        {
            bool mybool = BitConverter::ToBool(buffer);
            return mybool ? "True" : "False";
        }
        case DATA_TYPE::DATETIME:
        {
            std::time_t mydt = BitConverter::ToDateTime(buffer);
            struct std::tm mytm;
            errno_t err = localtime_s(&mytm, &mydt);
            if (err)
            {
                return "Invalid date and time";
            }
            else
            {
                int year = 1900 + mytm.tm_year;
                int month = 1 + mytm.tm_mon;
                int day = mytm.tm_mday;
                int hour = mytm.tm_hour;
                int minute = mytm.tm_min;
                int second = mytm.tm_sec;
                return std::format("{:02}/{:02}/{:04}T{:02}:{:02}:{:02}", day, month, year, hour, minute, second);
            }

        }
        case DATA_TYPE::DOUBLE:
        {
            double mydouble = BitConverter::ToDouble(buffer);
            const int sigdigits = std::numeric_limits<double>::digits10;
            std::ostringstream out;
            out << std::setprecision(sigdigits) << mydouble;
            return out.str();
        }
        case DATA_TYPE::ERROR:
            return "Error";
        case DATA_TYPE::INT:
        {
            int myint = BitConverter::ToInt(buffer);
            std::ostringstream out;
            out << myint;
            return out.str();
        }
        case DATA_TYPE::LONG:
        {
            int mylong = BitConverter::ToLong(buffer);
            std::ostringstream out;
            out << mylong;
            return out.str();
        }
        case DATA_TYPE::STRING:
        {
            std::string mystring = BitConverter::ToString(buffer);
            return mystring;
        }
        case DATA_TYPE::UNDEFINED:
            return "Undefined";
        default:
            return "";
        }
    }

    Variant* Variant::operator=(Variant value) { Set(value); return this; }
    Variant* Variant::operator=(data value) { Set(value); return this; }
    Variant* Variant::operator=(bool value) { Set(value); return this; }
    Variant* Variant::operator=(int value) { Set(value); return this; }
    Variant* Variant::operator=(long value) { Set(value); return this; }
    Variant* Variant::operator=(double value) { Set(value); return this; }
    Variant* Variant::operator=(std::string value) { Set(value); return this; }
    Variant* Variant::operator=(std::time_t value) { Set(value); return this; }
    
    Variant Variant::operator+(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;

            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                int varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                std::string s1 = (std::string)mydata;
                std::string s2 = (std::string)variant.Data();
                std::string ret = s1 + s2;
                Variant vret(ret);
                return vret;
            }
            }
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                long varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                std::string s1 = (std::string)mydata;
                std::string s2 = (std::string)variant.Data();
                std::string ret = s1 + s2;
                Variant vret(ret);
                return vret;
            }
            }
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                double varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                double varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 + var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                std::string s1 = (std::string)mydata;
                std::string s2 = (std::string)variant.Data();
                std::string ret = s1 + s2;
                Variant vret(ret);
                return vret;
            }
            }
        }
        break;
        default:
        {
            std::string s1 = (std::string)mydata;
            std::string s2 = (std::string)variant.Data();
            std::string ret = s1 + s2;
            Variant vret(ret);
            return vret;
        }
        }
    }
    Variant Variant::operator+(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            int varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            std::string s1 = (std::string)mydata;
            std::ostringstream out;
            out << value;
            std::string s2 = out.str();
            std::string ret = s1 + s2;
            Variant vret(ret);
            return vret;
        }
        }
    }
    Variant Variant::operator+(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            long varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            std::string s1 = (std::string)mydata;
            std::ostringstream out;
            out << value;
            std::string s2 = out.str();
            std::string ret = s1 + s2;
            Variant vret(ret);
            return vret;
        }
        }
    }
    Variant Variant::operator+(double value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            double varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            double varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 + value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            std::string s1 = (std::string)mydata;
            std::ostringstream out;
            out << value;
            std::string s2 = out.str();
            std::string ret = s1 + s2;
            Variant vret(ret);
            return vret;
        }
        }
    }
    Variant Variant::operator+(std::string& value)
    {
        std::string s1 = (std::string)mydata;
        std::string ret = s1 + value;
        Variant vret(ret);
        return vret;
    }
    Variant Variant::operator+(const char* value)
    {
        std::string s1 = (std::string)mydata;
        std::string s2(value);
        std::string ret = s1 + s2;
        Variant vret(ret);
        return vret;
    }

    Variant Variant::operator-(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;

            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                int varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                long varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                double varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                double varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 - var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator-(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            int varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator-(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            long varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator-(double value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            double varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            double varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 - value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    
    Variant Variant::operator*(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;

            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                int varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                long varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                double varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                double varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 * var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator*(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            int varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator*(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            long varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator*(double value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            double varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            double varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 * value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    
    Variant Variant::operator/(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;

            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                int varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                long varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                double varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                double varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::DOUBLE:
            {
                double var2 = (double)variant.Data();
                double varR = var1 / var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator/(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            int varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator/(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            long varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator/(double value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            double varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            double varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::DOUBLE:
        {
            double var1 = (double)mydata;
            double varR = var1 / value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }

    Variant Variant::operator%(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;

            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                int varR = var1 % var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 % var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::INT:
            {
                int var2 = (int)variant.Data();
                long varR = var1 % var2;
                Variant vret(varR);
                return vret;
            }
            break;
            case DATA_TYPE::LONG:
            {
                long var2 = (long)variant.Data();
                long varR = var1 % var2;
                Variant vret(varR);
                return vret;
            }
            break;
            default:
            {
                throw std::invalid_argument("It's not allowed...");
            }
            }
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator%(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            int varR = var1 % value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 % value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }
    Variant Variant::operator%(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::INT:
        {
            int var1 = (int)mydata;
            long varR = var1 % value;
            Variant vret(varR);
            return vret;
        }
        break;
        case DATA_TYPE::LONG:
        {
            long var1 = (long)mydata;
            long varR = var1 % value;
            Variant vret(varR);
            return vret;
        }
        break;
        default:
        {
            throw std::invalid_argument("It's not allowed...");
        }
        }
    }

    Variant Variant::operator<(Variant& variant)
    {
        double var1, var2;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        switch (variant.Type())
        {
        case DATA_TYPE::INT: { var2 = (int)variant.Data(); } break;
        case DATA_TYPE::LONG: { var2 = (long)variant.Data(); } break;
        case DATA_TYPE::DOUBLE: { var2 = (double)variant.Data(); } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 < var2) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator<(int value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 < value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator<(long value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 < value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator<(double value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 < value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    
    Variant Variant::operator<=(Variant& variant)
    {
        double var1, var2;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        switch (variant.Type())
        {
        case DATA_TYPE::INT: { var2 = (int)variant.Data(); } break;
        case DATA_TYPE::LONG: { var2 = (long)variant.Data(); } break;
        case DATA_TYPE::DOUBLE: { var2 = (double)variant.Data(); } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 <= var2) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator<=(int value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 <= value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator<=(long value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 <= value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator<=(double value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 <= value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    
    Variant Variant::operator>(Variant& variant)
    {
        double var1, var2;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        switch (variant.Type())
        {
        case DATA_TYPE::INT: { var2 = (int)variant.Data(); } break;
        case DATA_TYPE::LONG: { var2 = (long)variant.Data(); } break;
        case DATA_TYPE::DOUBLE: { var2 = (double)variant.Data(); } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 > var2) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator>(int value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 > value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator>(long value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 > value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator>(double value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 > value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    
    Variant Variant::operator>=(Variant& variant)
    {
        double var1, var2;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        switch (variant.Type())
        {
        case DATA_TYPE::INT: { var2 = (int)variant.Data(); } break;
        case DATA_TYPE::LONG: { var2 = (long)variant.Data(); } break;
        case DATA_TYPE::DOUBLE: { var2 = (double)variant.Data(); } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 >= var2) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator>=(int value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 >= value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator>=(long value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 >= value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator>=(double value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 >= value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    
    Variant Variant::operator==(Variant& variant)
    {
        double var1, var2;

        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN: { var1 = (bool)mydata; } break;
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: 
        {
            std::string s1 = (std::string)mydata;
            std::string s2 = (std::string)variant.Data();
            bool retX = (s1 == s2) ? true : false;
            Variant vRetX(retX);
            return vRetX;
        }
        }
        switch (variant.Type())
        {
        case DATA_TYPE::BOOLEAN: { var2 = (bool)variant.Data(); } break;
        case DATA_TYPE::INT: { var2 = (int)variant.Data(); } break;
        case DATA_TYPE::LONG: { var2 = (long)variant.Data(); } break;
        case DATA_TYPE::DOUBLE: { var2 = (double)variant.Data(); } break;
        {
            std::string s1 = (std::string)mydata;
            std::string s2 = (std::string)variant.Data();
            bool retX = (s1 == s2) ? true : false;
            Variant vRetX(retX);
            return vRetX;
        }
        }
        bool ret = (var1 == var2) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator==(bool value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN: { var1 = (bool)mydata; } break;
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 == value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator==(int value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN: { var1 = (bool)mydata; } break;
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 == value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator==(long value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN: { var1 = (bool)mydata; } break;
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 == value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator==(double value)
    {
        double var1;

        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN: { var1 = (bool)mydata; } break;
        case DATA_TYPE::INT: { var1 = (int)mydata; } break;
        case DATA_TYPE::LONG: { var1 = (long)mydata; } break;
        case DATA_TYPE::DOUBLE: { var1 = (double)mydata; } break;
        default: throw std::invalid_argument("It's not allowed...");
        }
        bool ret = (var1 == value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }
    Variant Variant::operator==(std::string value)
    {
        std::string var1;

        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN: throw std::invalid_argument("It's not allowed...");
        case DATA_TYPE::INT: throw std::invalid_argument("It's not allowed...");
        case DATA_TYPE::LONG: throw std::invalid_argument("It's not allowed...");
        case DATA_TYPE::DOUBLE: throw std::invalid_argument("It's not allowed...");
        default:
            var1 = (std::string)mydata;
        }
        bool ret = (var1 == value) ? true : false;
        Variant vRet(ret);
        return vRet;
    }

    Variant Variant::operator&&(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            switch (variant.Type()) 
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::DOUBLE:
            {
                double b2 = (double)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            switch (variant.Type()) 
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::DOUBLE:
            {
                double b2 = (double)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            switch (variant.Type()) 
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::DOUBLE:
            {
                double b2 = (double)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        case DATA_TYPE::DOUBLE:
        {
            double b1 = (double)mydata;
            switch (variant.Type()) 
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::DOUBLE:
            {
                double b2 = (double)variant.Data();
                bool ret = b1 && b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator&&(bool value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::DOUBLE:
        {
            double b1 = (double)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator&&(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::DOUBLE:
        {
            double b1 = (double)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator&&(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::DOUBLE:
        {
            double b1 = (double)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator&&(double value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::DOUBLE:
        {
            double b1 = (double)mydata;
            bool ret = b1 && value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }

    Variant Variant::operator^(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 ^ b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator^(bool value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator^(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator^(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 ^ value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }

    Variant Variant::operator||(Variant& variant)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            switch (variant.Type())
            {
            case DATA_TYPE::BOOLEAN:
            {
                bool b2 = (bool)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::INT:
            {
                int b2 = (int)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            case DATA_TYPE::LONG:
            {
                long b2 = (long)variant.Data();
                bool ret = b1 || b2;
                Variant vRet(ret);
                return vRet;
            }
            default:
                throw std::invalid_argument("It's not allowed...");
            }
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator||(bool value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator||(int value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }
    Variant Variant::operator||(long value)
    {
        switch (mydata.type)
        {
        case DATA_TYPE::BOOLEAN:
        {
            bool b1 = (bool)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::INT:
        {
            int b1 = (int)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        case DATA_TYPE::LONG:
        {
            long b1 = (long)mydata;
            bool ret = b1 || value;
            Variant vRet(ret);
            return vRet;
        }
        default:
            throw std::invalid_argument("It's not allowed...");
            break;
        }
    }

}

