#include <iostream>
#include <string>

/*
 * Dynamic Size
 * Works with operations
 * Part of std namespace
*/
using namespace std;

int main()
{
    string s1; // uninitialized
    string s2 {"Osameh"}; // initalized
    string s3 {s2}; // deep copied
    string s4 {"Osameh", 3}; // slice from 0
    string s5 {"Osameh", 1, 2}; // slice between indexes
    string s6 {3, 'O'}; // replicate 'O' 3 times
    
    s1 = "By assignment!!";
    
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    
    cout << "Concat: " << s1 + ' ' + s2 << endl;
    
    // Array notation
    cout << s2[1] << endl;
    
    // Vector .at() method
    cout << s3.at(0) << endl;
    
    s4.push_back('X');
    
    cout << s4 << endl;
    
    cout << "is " << s2 << " equal to "
    << s3 << "?" << (s2 == s3) << endl;
    
    cout << "Searching for ment in s1 by s1.find(\"ment\")\n";
    cout << "Found at index: " <<s1.find("ment") << endl;
    
    // The find method also accepts a starting position
    size_t pos = s1.find("ment");
    
    // string::npos is returned if string not found
    if (pos == string::npos)
        cout << "\"ment\" not found\n";
    else
        cout << "\"ment\" was found at index " << pos << endl;
    cout << s1.find("ment", 4) << endl;
    
    // Search in the reverse direction
    cout << s1.rfind("ment") << endl;
    
    // Erase part of the string start at 1 and erase 3 chars
    s4 = s1.erase(1, 3);
    cout << s4 << endl;
    
    // Substring
    cout << "Substring " << s1.substr(0, 3) << endl;
    
    // Clear the string
    
    s4.clear();
    
    cout << "Printing s4 after calling clear(): " << s4 << endl;
    
    // Length
    
    cout << s1.length() << endl;
    
    // concat assignmnet
    
    s1 += s2;
    s1 += s3;
    
    cout << s1 << endl;
    
    // getline
    
    getline(cin, s1); // get a line into s1
    cout << s1 << endl;
    
    getline(cin, s1, ' '); // get line, but stop at space ' '. THIS MAY GET MULTIPLE LINES
    cout << s1 << endl;
    
    
    // Range based loop
    for (char c: s1)
        cout << c << " ";
    cout << endl;
    
    return 0;
}