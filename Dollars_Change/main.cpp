#include <iostream>

using namespace std;

/*
 * The user enters an amouont in cents
 * You should specify how are you going to give
 * this amount to the user in
 * Dollars, Quarters, Dimes, Nickels, and Pennies 

 * Steps:
 * 1) Ask about amount in cents
 * 2) Divide by 100 ==> Result = Dollars, remainder = cents
 * 3) Divde by 25 ==> Result = Quarters, remainder = cents
 * 4) Divde by 10 for dimes, 
 * 5) then by 5 for nickels
 * 
 * */



int main()
{
    cout << "Enter amount in cents: ";
    int cents;
    cin >> cents;
    // Finding dollars
    int dollars = cents / 100;
    cout << "Dollars: " << dollars << endl;
    cents = cents % 100;
    // Finding quarters
    int quarters = cents / 25;
    cout << "Quarters: " << quarters << endl;
    cents = cents % 25;
    // Finding Dimes
    int dimes = cents / 10;
    cout << "Dimes: " << dimes << endl;
    cents = cents % 10;
    // Finding Nickels
    int nickels = cents / 5;
    cout << "Nickels: " << nickels << endl;
    cents = cents % 5;
    // The remaining amount is cents
    cout << "Cents: " << cents << endl;
    
    
    return 0;
}