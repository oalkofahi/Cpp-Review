#include <iostream>
#include <vector>
#include <typeinfo>
#include <cstring>

using namespace std;

void print(int A[], int size, int epr)
{
    for(int i = 0; i < size; i++)
    {
        if(i % epr == 0 && i > 0)
            cout << endl;
        cout << A[i] << " ";
    }
    cout << endl;

}

void print(int A[], int size)
{
    const char * itype = typeid(int).name();
    cout << "Type of int: " << itype << endl;
    //for(int i = 0; typeid(A[i]).name() == itype; i++)
    for(int i = 0; i < size; i++)
    {
        cout << "Type of A[i]: " << typeid(A[i]).name() << endl;
        cout << A[i] << " ";
        
    }
    cout << "A[size] = " << A[size] << endl;
    cout <<"Type of A[size]: " << typeid(A[size]).name() << endl;
    cout << endl;
    

}

void print(double A[], int size)
{
    const char * itype = typeid(double).name();
    cout << "Type of double: " << itype << endl;
    //for(int i = 0; typeid(A[i]).name() == itype; i++)
    for(int i = 0; i < size; i++)
    {
        cout << "Type of A[i]: " << typeid(A[i]).name() << endl;
        cout << A[i] << " ";
        
    }
    cout << "A[size] = " << A[size] << endl;
    cout <<"Type of A[size]: " << typeid(A[size]).name() << endl;
    cout << endl;
    

}

void print(double A[])
{
    const char * itype = typeid(double).name();
    cout << "Printing Array of Type: " << itype << endl;
    for(int i = 0; strcmp(typeid(A[i]).name(),itype) == 0; i++)
    //for(int i = 0; i < size; i++)
    {
        cout << "Type of A[i]: " << typeid(A[i]).name() << endl;
        cout << A[i] << " ";
        
    }
   
    cout << endl;
    

}

void print(vector <int> & vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;
}


int main()
{
    
  /*  int const rows = 5;
    int const cols = 5;
    int A[rows][cols];
    
    for (int i = 0; i< rows;i++)
        for (int j =0; j < cols; j++)
            A[i][j] = i+j;
            
    print(A[0], rows*cols, cols);*/
 /*   for (int i = 0; i< rows;i++)
    {
        for (int j =0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    */
    /*
    ////////////// VECTORS ///////////////////
    // Vectors are dynamic arrays
    // Part of the STL
    // Syntax:
    // #include<vector>
    // vector <type> name;
    // By defult the values in a vector are initialized to zeros
    */
      /*   
    int vrows, vcols;
    
    cout << "Enter number of rows:";
    cin >> vrows;
    cout << "Enter number of columns:";
    cin >> vcols;
    
    vector <int> iv(vrows);//[cols];
    vector <double> dv {0.2, 3.4}; // Using initializers list
    
    // The follwing does not work
    //print(iv, vrows*vcols, vcols);
    /*
    for (int i = 0; i < vrows; i++)
       for(int j = 0; j < vcols; j++)
           cout << iv[i][j];
   */
   /*
   cout << iv[0] << endl; 
   cout << dv[1] << endl;
   cout << dv[2] << endl; // no bound checking is done when using [] // THIS WILL PRINT RUBBISH
   // WE can use .at(index) to access elements
   cout << dv.at(0) << endl;
   // cout << dv.at(2) << endl; // will throw an exception because this is out of bounds
   
   // add an element at the edn of the vector
   // MUST be of the same type of data in the vector
   dv.push_back(4.5);
   cout << dv.at(2) << endl; // will work now
   cout << "The vector now has " << dv.size() << " elements\n";
   
   // enter values into vectors
   cout << "Enter a value to store in the vector: ";
   cin >> dv.at(0); // Must choose an element index to replace within range
   cout << "The value stored is " << dv.at(0) << endl;
   
   
   // 2D vectors
   
   vector <vector <int>> vec2d {{2, 3}, {3, 4}};

   
   cout << vec2d [0][0] << endl;
   cout << vec2d.at(0).at(0) << endl;*/
   
   
   // declare 2 vectors
   double M[] {1,2,3,4,5};
   print(M, 5);
   
   vector <int> vec1, vec2;
   
   vec1.push_back(10);
   vec1.push_back(20);
   
   cout << vec1.at(0) << endl;
   cout << vec1.at(1) << endl;
   
   vec2.push_back(100);
   vec2.push_back(200);
   
   cout << vec2.at(0) << endl;
   cout << vec2.at(1) << endl;
   
   cout << "The values in vec1 are:\n";
   print(vec1);
   cout << "The values in vec2 are: \n";
   print(vec2);


    // dcelare 2d vector
    
    vector <vector <int>> vec2d;
    
    cout << "Combining Both vectors into 2D vector\n";
    
    vec2d.push_back(vec1);
    vec2d.push_back(vec2);
    
    for (int i = 0; i < vec2d.size(); i++)
        print(vec2d.at(i));
    
    vec1.at(0) = 1000;
    
    cout << "Printing 2D vector after setting vec1[0] to 1000\n";
    
    for (int i = 0; i < vec2d.size(); i++)
        print(vec2d.at(i));
    
    print(vec1);
    
    
    return 0;
}