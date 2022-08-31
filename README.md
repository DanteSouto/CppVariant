# C++ 20 Variant data/object type implementation

Variant data/object type with array suport implementation.

## Current supported data types:

* bool;
* int;
* long;
* double;
* std::string;
* std::time_t;
* array.

## Usage

Declaring var1 as Variant data type

	lsvbs::Variant var1;

### Using direct association:

	var1 = 10;	// var1 assuming int data type
	var1 = true;	// var1 assuming bool data type
	var1 = 10L;	// var1 assuming long data type
	var1 = 10.5;	// var1 assuming double data type
	var1 = std::string(“testing”);	// var1 assuming string data type
	var1 = std::time(0); 	// var1 assuming date and time data type;

### Using Set and Get method:

	var1.Set(10);	// var1 assuming int data type
	
	double dblvar = 10.5;
	var1.Set(dblvar);	// var1 assuming double data type
	
	double dvar2;
	dvar2 = var1.Get<double>();		// dvar2 now contains 10.5

### Logic Operators

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

output:

	Logic Operator True AND False = False
	Logic Operator True OR False = True
	Logic Operator True XOR False = True

### Comparation Operators

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
	std::cout << "Compatarion " + v1.ToString() + " >= " + v2.ToString() + " = " + bVar.ToString() + "\r\n";

	bVar = v1 <= v2;
	std::cout << "Compatarion " + v1.ToString() + " <= " + v2.ToString() + " = " + bVar.ToString() + "\r\n";

	bVar = v1 == v2;
	std::cout << "Compatarion " + v1.ToString() + " == " + v2.ToString() + " = " + bVar.ToString() + "\r\n";
	
Output

	Compatarion 10 > 100 = False
	Compatarion 10 < 100 = True
	Compatarion 10 >= 100 = False
	Compatarion 10 <= 100 = True
	Compatarion 10 == 100 = False

### Aritimetic operations and string concatenation

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

	// perform string concatenation
	v1 = std::string("Hey");
	v2 = std::string("You");
	bVar = v1 + " " + v2;
	std::cout << "Concatenation " + v1.ToString() + " + ' ' + " + v2.ToString() + " = " + bVar.ToString() + "\r\n";

Output

	Operation 10 + 2 = 12
	Operation 10 - 2 = 8
	Operation 10 * 2 = 20
	Operation 10 / 2 = 5
	Operation 10 % 2 = 0
	Concatenation Hey + ' ' + You = Hey You

### Array operations

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

Output

	Size before POP: 4
	Size after POP: 3
	Size before INSERT: 3
	Size after INSERT: 4
	array[0]: Type=Integer Value=100
	array[1]: Type=DateAndTime Value=30/08/2022T20:50:54
	array[2]: Type=Boolean Value=True
	array[3]: Type=String Value=testing...again

## Meta

Dante Souto – [@dantesouto](https://twitter.com/dantesouto)

Distributed under the MIT license. See ``LICENSE`` for more information.

[https://github.com/DanteSouto/](https://github.com/DanteSouto/)
