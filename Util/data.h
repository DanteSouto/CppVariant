#pragma once
#include "globais.h"

namespace lsvbs
{

    struct data
    {
        bytes buffer;
        DATA_TYPE type;
        operator bool() const;          // { return BitConverter::ToBool(buffer); }
        operator int() const;           // { return BitConverter::ToInt(buffer); }
        operator long() const;          // { return BitConverter::ToLong(buffer); }
        operator double() const;        // { return BitConverter::ToDouble(buffer); }
        operator std::string() const;   // { return ToString(); }
        operator std::time_t() const;   // { return BitConverter::ToDateTime(buffer); }
        std::string ToString() const;
    };
}