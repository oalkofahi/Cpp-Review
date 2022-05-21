#include <iostream>
#include <vector>

using namespace std;


//void fun(Move &);

class Move {
friend void fun(Move &m);
private:
    int * data;
    static int number;
    
public:
    void set_data(int x) {*data = x;}
    int get_data() {return *data;}
    Move() {
        cout << "Default Constructor\n";
        data = nullptr;
        number++;
    }
    Move(int x) {
        cout << "Argument Constructor with val = "
        << x << endl;
        data = new int;
        *data = x;
        number++;
        }
    Move(const Move &from) {
        cout << "Copy Constructor From "
        << *from.data << endl;
        data = new int;
        *data = *(from.data);
        number++;
        }
    ~Move() {
        cout <<"Destructor of " << (data == nullptr? 0:*data) << endl;
        number--;
        }
    
    // Move constructore
    // Note that && here defines a reference to an R-Value
    // R-values can be temporary objects that are created on the fly
    // Like the pushed objects in the vector in main
    Move(Move &&from){
        // We want to STEAL the data from the source
        // Without allocating new storage and copying
        cout <<"Move Constructor of " << *from.data << endl;
        data = from.data;
        // The following is important
        // Otherwise we'll end up with a shallow copy and not a move
        // Since two objects will be pointing to the same value
        from.data = nullptr;
        number++;
    }
    
    static int get_number() {return number;}
    
};

// initialize static data member cannot be done inside class
int Move::number = 0;

void fun(Move &m)
{
    cout << "Printing from friend function: " << *m.data << endl;
}

void func()
{
    static int num = 0;
    num++;
    cout << "function called " << num << " times\n";
}

int main()
{
    vector <Move> vec;
    vec.push_back(Move{10}); // These are temp values
    vec.push_back(Move{20}); // Copy constructir will be called unless we define a Move constructor which is the purpose of this code
    cout << "number of objects: " << Move::get_number() << endl;
    func();
    func();
    func();
    fun(vec.front());
    
    return 0;
}