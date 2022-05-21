#include <iostream>
#include<cctype>
/* The cctype library is useful for
 * 1) Tests
 * isalpha(), isalnum(), isdigit()
 * islower(), isprint(), ispunct()
 * isupper(), isspace()
 * 2) Conversion
 * tolower(), toupper()
 * 
 * C-Style Strings char arrays or char * 
 * terminated with NULL or \0
*/
#include<cstring>
// Another library for C-strings
// strlen(), strcpy(), strcat()
 
using namespace std;

int main()
{
    cout << "Enter 1st sentence: ";
    char sent1[50] {};
    char sent2[50] {};
    cin.getline(sent1, 50);
    
    cout << sent1 << endl;
    return 0;
}