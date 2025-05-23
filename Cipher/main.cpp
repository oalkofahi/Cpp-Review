#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

void randomize(string & alph)
{
    size_t str_size = alph.length();
    size_t pos1 {};
    size_t pos2 {};
    char tmp {};
    for (int i = 0; i < str_size * 3; i++)
    {
        pos1 = rand() % str_size;
        pos2 = rand() % str_size;
        //cout << "swapping positions " << pos1 << " and " << pos2 << endl;
        tmp = alph.at(pos1);
        alph.at(pos1) = alph.at(pos2);
        alph.at(pos2) = tmp;
    }

}

void encrypt (string & msg, const string & alph, const string & key)
{
    size_t index {};
    for(int i = 0; i < msg.length(); i++)
    {
        char c = msg.at(i);
        //cout <<"replacing " << c << " with ";
        index = alph.find(c);
        if(index != string::npos)
            msg.at(i) = key.at(index);
        //cout << msg.at(i) << endl;            
    }
}

void decrypt (string & msg, const string & alph, const string & key)
{
    encrypt(msg, key, alph);
}

int main()
{
    srand(time(0));
    string alphabet {" 01234567890.,;:()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {alphabet};
    randomize(key);
    cout << "Alpgabet is: " << alphabet << endl;
    cout << "Key is     : " << key << endl;
    cout << "Enter message to encrypt: ";
    string msg {};
    getline(cin, msg);
    encrypt(msg, alphabet, key);
    cout << "Message after encryption:\n";
    cout << msg << endl;
    decrypt(msg, alphabet, key);
    cout << "Message after decryption:\n";
    cout << msg << endl;
    
    return 0;
}