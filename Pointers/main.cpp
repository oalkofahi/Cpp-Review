#include <iostream>
#include <string>
#include <vector>
using namespace std;

///////////////////// PASSIN Pointers to functions /////////////
void double_val(int * const ptr)
{
    *ptr *= 2;
}

// Passing pointers by reference JUST FOR FUN
void addptr(const int * &p)
{
    p++;
}

void print(const int * p, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *p << ' ';
        addptr(p);
    }
    cout << endl;
}

void swap(int * const ptr1, int * const ptr2)
{
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}


void print(vector<string> * ptr)
{
    for(auto n: *ptr)
        cout << n << " ";
    cout << endl; 
}

int main()
{
    vector <string> names {"Ali", "Ahmed", "Rami"};
    print(&names);
}

//
//int main()
//{
//    int x = 1;
//    double_val(&x);
//    cout << x << endl;
//    
//    
//    int A[] {1,2,3,4,5};
//    print(A, 5);
//    
//    int a = 1;
//    int b = 2;
//    
//    cout << "Before swap: a = " << a << " and b = " << b << endl;
//    swap(&a, &b);
//    cout << "After swap: a = " << a << " and b = " << b << endl;
//    return 0;
//}

//////////////////////// Const and Pointers ////////////////
//int main()
//{
//    // CASE 1: non const ptr and non const int
//    int x {1};
//    int y {2};
//    int * p1 = &x;
//    
//    // x can change
//    x = 2;
//    // the ptr can change
//    p1 = &y;
//    
//    // CASE 2: non const ptr to const int
//    const int a {1};
//    const int b {2};
//    
//    const int * p2 = &a;
//    
//    // int cannot change
//    // *p2 = 4; // error
//    
//    // ptr can change
//    p2 = &b;
//    
//    // CASE 3: const ptr to non const int
//    int c {1};
//    int d {2};
//    
//    int * const p3 = &c;
//    
//    // int can change
//    *p3 = 4;
//    
//    // ptr cannot change
//    //p3 = &d; //error
//    
//    // CASE 4: const ptr to const int
//    const int e {1};
//    const int f {2};
//    
//    const int * const p4 = &e;
//    
//    // int cannot change
//    //*p4 = 2; //error
//    
//    // ptr cannot change
//    //p4 = &f;
//    return 0;
//
//}




//
//int main()
//{
//    int *iptr {nullptr};
//    
//    iptr = new int;
//    cout << iptr << endl;
//    *iptr = 5;
//    cout << *iptr << endl;
//    
//    delete iptr; // frees the storage, but does not delete the pointer
//    
//    size_t size {0};
//    
//    double * dptr {nullptr};
//    cout << "size?";
//    cin >> size;
//    
//    dptr = new double[size];
//    double * ptr = dptr;
//    for (int i = 0; i < size; i++)
//        dptr[i] = i;
//    for(int i = 0; i < size; i++)
//        cout << dptr[i] << " ";
//    cout << endl;
//    
//    
//    return 0;
//}