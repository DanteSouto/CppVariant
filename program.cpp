// Dante Souto
// 2022
// dantesouto@gmail.com

#include "program.h"

int main()
{
    TestDataTypes();
    TestLogicOperator();
    TestComparationOperators();
    TestAritimeticOperators();
    TestPushPullPopRemoveInsert();
    testes();
	return 0;
}

void TestDataTypes()
{
    std::cout << "\r\n\r\nSuported Data Types\r\n";
    lsvbs::Variant vArray;

    lsvbs::Variant vBool;
    vBool = true;
    vArray.Push(vBool);

    lsvbs::Variant vInt;
    vInt = 10;
    vArray.Push(vInt);

    lsvbs::Variant vLong;
    vLong = 100L;
    vArray.Push(vLong);
    
    lsvbs::Variant vDouble;
    vDouble = 123.45;
    vArray.Push(vDouble);
    
    lsvbs::Variant vString;
    vString = std::string("Testing...");
    vArray.Push(vString);
    
    lsvbs::Variant vDateTime;
    vDateTime = std::time(0);   // now
    vArray.Push(vDateTime);

    for (int i = 0; i < vArray.Count(); i++) 
    {
        std::cout << "Variant Data Type: " + vArray[i].TypeName() + ", and the value is: " + vArray[i].ToString() + "\r\n";
    }
}

void TestLogicOperator()
{
    std::cout << "\r\n\r\nLogic Operators\r\n";

    lsvbs::Variant bVar;
    lsvbs::Variant v1;
    lsvbs::Variant v2;
    v1 = true;
    v2 = false;
    bVar = v1 && v2;
    std::cout << "Logic Operator " + v1.ToString() + " AND " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 || v2;
    std::cout << "Logic Operator " + v1.ToString() + " OR " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 ^ v2;
    std::cout << "Logic Operator " + v1.ToString() + " XOR " + v2.ToString() + " = " + bVar.ToString() + "\r\n";

}

void TestComparationOperators()
{
    std::cout << "\r\n\r\nComparation Operators\r\n";

    lsvbs::Variant bVar;
    lsvbs::Variant v1;
    lsvbs::Variant v2;
    v1 = 10;
    v2 = 100;
    bVar = v1 > v2;
    std::cout << "Compatarion " + v1.ToString() + " > " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 < v2;
    std::cout << "Compatarion " + v1.ToString() + " < " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 >= v2;
    std::cout << "Logic " + v1.ToString() + " >= " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 <= v2;
    std::cout << "Logic " + v1.ToString() + " <= " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 == v2;
    std::cout << "Logic " + v1.ToString() + " == " + v2.ToString() + " = " + bVar.ToString() + "\r\n";

}

void TestAritimeticOperators()
{

    std::cout << "\r\n\r\nAritimetic Operators\r\n";

    lsvbs::Variant bVar;
    lsvbs::Variant v1;
    lsvbs::Variant v2;
    v1 = 10;
    v2 = 2;
    bVar = v1 + v2;
    std::cout << "Operation " + v1.ToString() + " + " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 - v2;
    std::cout << "Operation " + v1.ToString() + " - " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 * v2;
    std::cout << "Operation " + v1.ToString() + " * " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 / v2;
    std::cout << "Operation " + v1.ToString() + " / " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
    
    bVar = v1 % v2;
    std::cout << "Operation " + v1.ToString() + " % " + v2.ToString() + " = " + bVar.ToString() + "\r\n";

    v1 = std::string("Hey");
    v2 = std::string("You");
    bVar = v1 + " " + v2;
    std::cout << "Concatenation " + v1.ToString() + " + ' ' + " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
}

void TestPushPullPopRemoveInsert()
{
    std::cout << "\r\n\r\nArray Operations\r\n";

    lsvbs::Variant array;
    array.Push(100);                                // 1
    array.Push(true);                               // 2
    array.Push(std::string("testing..."));          // 3
    array.Pull(std::string("testing...again"));     // stil 3
    array.Push(10.5);                               // 4
    std::cout << "Size before POP: " + stringify(array.Count()) + "\r\n";
    array.Pop();                                    // 3
    std::cout << "Size after POP: " + stringify(array.Count()) + "\r\n";
    std::cout << "Size before INSERT: " + stringify(array.Count()) + "\r\n";
    array.Insert(1, time(0));                       // 4
    std::cout << "Size after INSERT: " + stringify(array.Count()) + "\r\n";
    for (int i = 0; i < array.Count(); i++)
    {
        std::cout << "array[" + stringify(i) + "]: Type=" + array[i].TypeName() + " Value=" + array[i].ToString() + "\r\n";
    }
}

void testes()
{
    lsvbs::data mydata;

    std::cout << "Testing BitConverter\r\n";
    bool mybool = true;
    mydata = lsvbs::BitConverter::GetBytes(mybool);
    bool mybool2 = lsvbs::BitConverter::ToBool(mydata.buffer);
    mybool = false;
    mydata = lsvbs::BitConverter::GetBytes(mybool);
    mybool = lsvbs::BitConverter::ToBool(mydata.buffer);
    mybool = true;

    std::cout << "test boolean: " + stringify<bool>(mybool) + " " + stringify<bool>(mybool2) + "\r\n";

    int myInt;
    myInt = 1234;
    mydata = lsvbs::BitConverter::GetBytes(myInt);
    int myInt2;
    myInt2 = lsvbs::BitConverter::ToInt(mydata.buffer);
    std::cout << "positive int: " + stringify<int>(myInt) + "=" + stringify<int>(myInt2) + "\r\n";
    
    myInt = -1234;
    mydata = lsvbs::BitConverter::GetBytes(myInt);
    myInt2 = lsvbs::BitConverter::ToInt(mydata.buffer);
    std::cout << "negative int: " + stringify<int>(myInt) + "=" + stringify<int>(myInt2) + "\r\n";

    long myLong;
    myLong = 1234;
    mydata = lsvbs::BitConverter::GetBytes(myLong);
    long myLong2;
    myLong2 = lsvbs::BitConverter::ToLong(mydata.buffer);
    std::cout << "positive long: " + stringify<long>(myLong) + "=" + stringify<long>(myLong) + "\r\n";

    myLong = -1234;
    mydata = lsvbs::BitConverter::GetBytes(myLong);
    myLong2 = lsvbs::BitConverter::ToLong(mydata.buffer);
    std::cout << "negative long: " + stringify<long>(myLong) + "=" + stringify<long>(myLong) + "\r\n";

    double myDouble = 1234.546;
    mydata = lsvbs::BitConverter::GetBytes(myDouble);
    double myDouble2;
    myDouble2 = lsvbs::BitConverter::ToDouble(mydata.buffer);
    std::cout << "positive double: " + stringify<double>(myDouble) + "=" + stringify<double>(myDouble2) + "\r\n";

    myDouble = -1234.546;
    mydata = lsvbs::BitConverter::GetBytes(myDouble);
    myDouble2 = lsvbs::BitConverter::ToDouble(mydata.buffer);
    std::cout << "negative double: " + stringify<double>(myDouble) + "=" + stringify<double>(myDouble2) + "\r\n";

    std::string s1 = "Hi Dante";
    mydata = lsvbs::BitConverter::GetBytes(s1);
    std::string s2 = lsvbs::BitConverter::ToString(mydata.buffer);
    std::cout << "string: " + s1 + "=" + s2 + "\r\n";

    std::time_t t1 = time(0);
    mydata = lsvbs::BitConverter::GetBytes(t1);
    std::time_t t2 = lsvbs::BitConverter::ToDateTime(mydata.buffer);
    std::cout << "Date and Time: " + stringify(t1) + "=" + stringify(t2) + "\r\n";

    std::cout << "\r\n\r\nTesting Variant\r\n";

    lsvbs::Variant v1;

    v1.Set(mybool);
    std::cout << "Variant v1 Type: " + v1.TypeName() + " Value: " + v1.ToString() + "\r\n";
    mybool2 = v1.Get<bool>();
    std::cout << "Variant Boolean: " + stringify<bool>(mybool) + "=" + stringify<bool>(mybool2) + "\r\n";
    mybool2 = (bool)v1.Data();
    std::cout << "Variant Boolean: " + stringify<bool>(mybool) + "=" + stringify<bool>(mybool2) + "\r\n";

    v1.Set(myInt);
    std::cout << "Variant v1 Type: " + v1.TypeName() + " Value: " + v1.ToString() + "\r\n";
    myInt2 = v1.Get<int>();
    std::cout << "Variant Int: " + stringify<int>(myInt) + "=" + stringify<int>(myInt2) + "\r\n";
    myInt2 = (int)v1.Data();
    std::cout << "Variant Int: " + stringify<int>(myInt) + "=" + stringify<int>(myInt2) + "\r\n";
    
    v1.Set(myLong);
    std::cout << "Variant v1 Type: " + v1.TypeName() + " Value: " + v1.ToString() + "\r\n";
    myLong2 = v1.Get<long>();
    std::cout << "Variant Long: " + stringify<long>(myLong) + "=" + stringify<long>(myLong2) + "\r\n";
    myLong2 = (long)v1.Data();
    std::cout << "Variant Long: " + stringify<long>(myLong) + "=" + stringify<long>(myLong2) + "\r\n";

    v1.Set(myDouble);
    std::cout << "Variant v1 Type: " + v1.TypeName() + " Value: " + v1.ToString() + "\r\n";
    myDouble2 = v1.Get<double>();
    std::cout << "Variant Double: " + stringify<double>(myDouble) + "=" + stringify<double>(myDouble2) + "\r\n";
    myDouble2 = (double)v1.Data();
    std::cout << "Variant Double: " + stringify<double>(myDouble) + "=" + stringify<double>(myDouble2) + "\r\n";

    v1.Set(s1);
    std::cout << "Variant v1 Type: " + v1.TypeName() + " Value: " + v1.ToString() + "\r\n";
    s2 = v1.Get<std::string>();
    std::cout << "Variant String: " + s1 + "=" + s2 + "\r\n";
    s2 = (std::string)v1.Data();
    std::cout << "Variant String: " + s1 + "=" + s2 + "\r\n";

    v1.Set(t1);
    std::cout << "Variant v1 Type: " + v1.TypeName() + " Value: " + v1.ToString() + "\r\n";
    t2 = v1.Get<std::time_t>();
    std::cout << "Variant DateTime: " + stringify<std::time_t>(t1) + "=" + stringify<std::time_t>(t2) + "\r\n";
    t2 = (std::time_t)v1.Data();
    std::cout << "Variant DateTime: " + stringify<std::time_t>(t1) + "=" + stringify<std::time_t>(t2) + "\r\n";

    lsvbs::Variant v2;
    lsvbs::data dt1 = v1.Data();
    v2.Set(dt1);
    t2 = v2.Get<std::time_t>();
    std::cout << "Variant Variant.Data() using t2: " + stringify<std::time_t>(t2) + "\r\n";

    v1.Set(s1);
    v2.Set(v1);
    s2 = v2.Get<std::string>();
    std::cout << "Variant pure Variant using s2: " + s2 + "\r\n";

    lsvbs::data dt2 = v1.Get<lsvbs::data>();
    v2.Set(dt2);
    s2 = v2.Get<std::string>();
    std::cout << "Variant Variant.Get<data>() using s2: " + s2 + "\r\n";

    v1 = v2.GetV();
    std::cout << "Variant using GetV: " + v1.Get<std::string>() + "\r\n";

    v2 = v1.Get<lsvbs::Variant>();
    std::cout << "Variant using Get<Variant>: " + v2.Get<std::string>() + "\r\n";

    std::cout << "\r\n\r\nTesting Variant Array\r\n";
    lsvbs::Variant va1;
    va1.Push(myLong);
    va1.Push(myDouble);
    va1.Push(t1);
    va1.Push(v1);
    //lsvbs::Variant vArray;
    for (int i = 0; i < va1.Count(); i++) 
    {
       // vArray = va1[i];
        std::cout << "Type of va1[" + stringify(i) + "]: " + va1[i].TypeName() + " Value: " + va1[i].ToString() + "\r\n";
    }


    std::cout << "\r\n\r\nTesting Variant Operators\r\n";
    lsvbs::Variant vSumA;
    lsvbs::Variant vSumB;
    lsvbs::Variant vSumC;
    lsvbs::Variant vSumD;
    lsvbs::Variant vSumE;
    lsvbs::Variant vSumF;
    lsvbs::Variant vRet;

    int int_val = 10;
    vSumA.Set(int_val);
    long long_val = 20;
    vSumB.Set(long_val);
    double double_val = 10.5;
    vSumC.Set(double_val);
    std::string string_val("Welcome");
    vSumD.Set(string_val);
    std::time_t date_val = time(0);
    vSumE.Set(date_val);
    bool bool_val = true;
    vSumF.Set(bool_val);

    vRet = vSumA + vSumB;
    std::cout << "Variant vSumA Type: " + vRet.TypeName() + " Value: " + vSumA.ToString() + "\r\n";
    std::cout << "Variant vSumB Type: " + vRet.TypeName() + " Value: " + vSumB.ToString() + "\r\n";
    std::cout << "Variant vSumB Type: " + vRet.TypeName() + " Value: " + vSumB.ToString() + "\r\n";
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    
    vRet = vSumA + vSumC;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumB + vSumC;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumC + vSumA;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumC + vSumB;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumD + vSumA;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumD + vSumB;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumD + vSumC;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumA + vSumD;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumB + vSumD;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumC + vSumD;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumD + vSumE;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumE + vSumD;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumF + vSumD;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";

    vRet = vSumA + 10;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumB + 10;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumC + 10;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    
    /*
    vRet = 10 + vSumA;
    std::cout << "vRet = 10 + vSumA Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = 10 + vSumB;
    std::cout << "vRet = 10 + vSumB Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = 10 + vSumC;
    std::cout << "vRet = 10 + vSumC Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    */

    vRet = vSumA + 10L;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumB + 10L;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumC + 10L;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    
    vRet = vSumA + 10.5;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumB + 10.5;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vRet = vSumC + 10.5;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";

    lsvbs::Variant vStringIoeratorTest;
    std::string string_test_operator1("Welcome");
    std::string string_test_operator2("Dante");
    vStringIoeratorTest.Set(string_test_operator1);
    vRet = vStringIoeratorTest + " " + string_test_operator2;
    std::cout << "Variant vRet Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";

    vSumA = 15;
    vSumB = 5;
    vRet = vSumA - vSumB;
    std::cout << "vSumB Type: " + vSumB.TypeName() + " Value: " + vSumB.ToString() + "\r\n";
    std::cout << "vRet = vSumA - vSumB Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";
    vSumB = 4.5;
    //myDouble = 4.5;
    //vSumB.Set(myDouble);
    std::cout << "vSumB Type: " + vSumB.TypeName() + " Value: " + vSumB.ToString() + "\r\n";
    vRet = vSumA - vSumB;
    std::cout << "vSumB Type: " + vSumB.TypeName() + " Value: " + vSumB.ToString() + "\r\n";
    std::cout << "vRet = vSumA - vSumB Type: " + vRet.TypeName() + " Value: " + vRet.ToString() + "\r\n";

}
