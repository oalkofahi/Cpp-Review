#include<iostream>
#include<typeinfo> // To use typeid(expression).name() to return the data type of expression
#include<iomanip> // To use output manipulators with arguments like setw() and setprecision()

using namespace std;

int main()
{
	// Unary operators
	{
		/*
		* In addition to the NOT (!) and the sizeof() operators, we have + and - sign operators
		*/
		cout << "Testing Unary Operators" << endl;
		int x = 4;
		int y = -6;
		cout << +x << endl;
		cout << -x << endl;
		cout << +y << endl;
		cout << -y << endl;

		cout << "The size of char = "  << sizeof(char) << endl;
		cout << "The size of bool = " << sizeof(bool) << endl;
		cout << "The size of int = " << sizeof(int) << endl;
		cout << "The size of float = " << sizeof(float) << endl;
		cout << "The size of double = " << sizeof(double) << endl;
		cout << "The size of long double = " << sizeof(long double) << endl;
					
	}
	{
		// Checking data types using typeid(var).name()
		cout << "Printing Data types using typeid().name()\n";
		cout << typeid(1).name() << endl; // prints int
		cout << typeid(1.1).name() << endl; // prints double
		cout << typeid(typeid(1).name()).name() << endl; // prints char const *
		cout << typeid(cout << "").name() << endl;

		/////////////////////////// Casting //////////////////////////////
        cout << "Static casting 5.345 to int";
		double d = 5.345;
		cout << static_cast<int>(d) << endl;
	}
	{
		//////////////////////////// OUTPUT MANIPULATORS /////////////////////////////
		// For bool variables
		cout << "***** Trying Bool output manipulators *****\n";
		bool b = true;
		cout << "Printing bool without manipulators\n";
		cout << b << endl;
		cout << "Using boolalpha manipulator\n";
		cout << boolalpha << b << endl;
		cout << "The affect sticks\n";
		cout << b << endl;
		cout << "To go back to bool 0/1 use noboolalpha\n";
		cout << noboolalpha << b << endl;
		// These manipulators can also be used with inputs
		cin >> boolalpha >> b;
		cout << "The value should be enetered as a word, but now we print without using any manipulator "  << b << endl;

		// Manipulators for different bases
		cout << "***** Different base amnipulators *****\n";
		int x = 22;
		cout << "Using dec for x = 22: " << dec << x << endl;
		cout << "Using oct and showbase to display the base for x = 22: " << oct << showbase << x << endl;
		cout << "Using hex for x = 22: " << hex << x << endl;
		cout << "Without any manipulators the last one will stick " << x << endl;
		cout << "Use dec and noshowbase again to make everything normal again " << dec << noshowbase << x << endl;

		// Manipulators for double
		cout << "***** Manipulators for double numbers *****\n";
		double d = 123;
		cout << "Printing 123 without any manipulators " << d << endl;
		cout << "Using the showpoint manipulator " << showpoint << d << endl;
		cout << "Using the noshowpoint manipulator " << noshowpoint << d << endl;
		cout << "Using the scientific manipulator " << scientific << d << endl;
		cout << "Using the fixed manipulator " << fixed << noshowpoint << d << endl;

		// Manipulators with arguments need the iomanip library
		cout << "Using the setw(20) mnipulator " << setw(20) << d << endl;
		cout << "Using the setprecision(0) " << setprecision(0) << d << endl;
		cout << d << endl;

		// ONLY setw(x) does not stick and needs to be used each time with cout

	}

	{
		// SELECTION STATEMENTS
		// You know if-else and switch
		int x = 4;

		switch (x)
		{
		case 0:
		case 1:
			cout << "x is 0 or 1\n";
			break;
		case 2:
			cout << "2 is 2\n";
			break;
            
		default:
			cout << "x is not 1, 0, or 2\n";
		}

		// The ternary operator
		cout << ((x == 4) ? "Yes" : "No") << endl;
	}
	return 0;
}