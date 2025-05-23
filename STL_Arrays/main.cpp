/*
 * Needs #include<array>
 * Object type: 
 * - has its size associated with it
 * - It DOES NOT decay into a pointer when passed to a function (unlike raw arrays)
 * Fixed size: must be known at compile time
 * Driect access to underlying raw array
 * Constant access time to elements regardless of number of elements
 * Should be used instead of raw arrays when possible
 * Part of STL: can be used with iterators and algorithms
 */
#include <iostream>
#include <array>
#include<algorithm>
#include<numeric>

int main()
{
    using namespace std;
    array<int, 5> arr1 {1,2,3,4,5};
    array<int, 5> arr2 {10,20,30,40,50};
    
    array<string, 3> arr3 {
        string("Larry"),
        "Roaa",
        string{"Salma"}
        };
        
    for(auto s: arr2)
        cout << s << " ";
    cout << endl;
    
    cout << arr1.size() << endl;
    
    cout << arr1[0] << endl;
    
    cout << arr1.front() << endl;
    
    cout << arr1.at(0) << endl;
    
    cout << arr1.back() << endl;
    
    cout << arr2.empty() << endl;
    
    cout << arr2.max_size() << endl;
    
    arr1.swap(arr2);
    
    for(auto n: arr1)
        cout << n << " ";
    cout << endl;
    
    int * data = arr1.data();// returns the raw array address
    
    for(size_t i = 0; i < arr1.size(); i++)
        cout << data[i] << " ";
    cout << endl;
    
    
    // sorting
    
    array <int, 10> arr4 {12,2,45,45,67,5,1,78,99};
    
    cout << "\n\nsize of arr4 = " << arr4.size() << endl;
    cout << "\n\nsize of arr4 = " << distance(arr4.begin(),arr4.end()) << endl;
    sort(arr4.begin(),arr4.end());
    
    for(int i: arr4)
        cout << i << " ";
    cout << endl;
    
    // Note that max_element returns an iterator to the max element, that is why we need to dereference afterwards
    cout << "arr4 max = " << *(max_element(arr4.begin(), arr4.end())) << endl;
    
    // Finding two similar adjacent elements
    auto adj_e = adjacent_find(arr4.begin(), arr4.end());
    
    if (adj_e != arr4.end())
        cout << "Found adjacent elements: " << *adj_e << " and " << *(adj_e + 1) << " starting at index " 
        << adj_e - arr4.begin() << endl;
        
    // Sum using accumulate function NEEDS #include<numeric>
    
    cout << "Sum = " << accumulate(arr4.begin(),arr4.end(),0);
    
    // count
    
    cout << "\n45 is found " << count(arr4.begin(),arr4.end(), 45) << " times\n";
    
    // count if
    
    cout << "number of even number in arr4 = " << count_if(arr4.begin(),arr4.end(), [] (int x) {return x%2 == 0;}) << endl;
    
    return 0;
}