#include <iostream>
#include "MyLib.h"

using namespace std;

int main()
{
    /*
    Account a;
    a.set_balance(10);
    cout << a.get_balance() << endl;
    
    Account b {"Ali", 30};
    cout << b.get_balance() << endl;
    return 0;
     
    */
    
    Player p1 = Player("P1", 30, 2);
    cout << p1.get_name() << endl;
    Player p2 = p1;
    cout << p2.get_name() << endl;
}