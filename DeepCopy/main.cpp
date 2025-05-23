#include <iostream>

using namespace std;

class Deep
{
private:
    int * data;
    
public:
    Deep(int d)
    {
        data = new int; //allocates storaget for int on heap and returns pointer
        *data = d;
    }
    Deep(const Deep &source)
    {
        // Deep copying
        // 1) Allocate new storage
        // 2) Then copy value
        // This creates two copies
        data = new int;
        *data = *source.data;
    }
    ~Deep()
    {
        delete data;
    }
};

int main()
{
    cout << "Hello\n";
    return 0;
}