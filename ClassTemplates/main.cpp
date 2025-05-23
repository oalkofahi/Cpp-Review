#include <iostream>


using namespace std;

/*
 * Class templates can also be defined
 * 
 * For class templates, we usually do NOT split the code into .h and .cpp files
 * 
 * Ysyally EVERYTHING is defined in the .h file
 */

template <typename T>
class Item {
private:
    T value;
    std::string name;
    
};

int main()
{
    cout << "Hello\n";
    return 0;
}