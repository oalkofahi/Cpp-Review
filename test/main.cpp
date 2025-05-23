#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum {
    SUN,
    MON,
    TUE
} days;

namespace sss
{
    int var;
}

int main()
{
    cout << "In main\n";
    sss::var = 0;
    cout << sss::var << endl;
    //days d(SUN);
    //cout << "Day = " << d << cout;
//    vector<string> words;
//    words.push_back(string("a"));
//    words.push_back(string("b"));
//    char c = 'c';
//    
//    //for (string w: words)
//    for (int i = 0; i < words.size(); i++)
//    {
//        //w.append(string(1,c));
//        words[i].push_back(c);
//        //cout << w << endl;
//    }
//    for (string w: words)
//        cout << w << endl;
    return 0;
}