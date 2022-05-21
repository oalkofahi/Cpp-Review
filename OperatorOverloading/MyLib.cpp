#include "MyLib.h"
#include <iostream>
#include <cstring>

Mystring::Mystring() : str{nullptr}
{
    str = new char[1];
    *str = '\0';    
}

Mystring::Mystring(const char * s)
: str{nullptr}
{
    std::cout <<"From char *\n";
    if(s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }    
}

Mystring::Mystring(const Mystring & source)
: str{nullptr}
{
    std::cout <<"Copying\n";
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);
}

Mystring::~Mystring()
{
    std::cout << "Deleting\n";
    delete [] str;
}

void Mystring::display() const 
{
    std::cout << str << " : " << length() << std::endl;
}

int Mystring::length() const
{
    return std::strlen(str);
}

const char * Mystring::get_str() const
{
    return str;
}

Mystring & Mystring::operator=(const Mystring &rhs)
{
    std::cout<<"Copy assignment Operator=\n";
    if (this == &rhs)
        return *this; 
        // recall that "this" is a pointer and we are returning a reference that is why we need to derefence first
        
    delete [] str;
    str = new char[std::strlen(rhs.str)+1];
    std::strcpy(str, rhs.str);
    
    return *this;
}

Mystring & Mystring::operator=(Mystring &&rhs)
{
    std::cout<<"Move assignment Operator=\n";
    if (this == &rhs)
        return *this; 
        // recall that "this" is a pointer and we are returning a reference that is why we need to derefence first
        
    delete [] str;
    
    str = rhs.str;
    
    rhs.str = nullptr;
    
    return *this;
}

Mystring Mystring::operator-() const
{
    std::cout << "Unary negation operator\n";
    char *buffer = new char[std::strlen(str)+1];
    std::strcpy(buffer, str);
    
    // Convert to lower case
    for(size_t i = 0; i < std::strlen(buffer); i++)
        buffer[i] = std::tolower(buffer[i]);
    
    Mystring tmp(buffer); // the copy to be returned
    delete [] buffer;
    return tmp;
}

bool Mystring::operator==(const Mystring &rhs) const
{
    int res = std::strcmp(str, rhs.str);
    if(res == 0)
        return true;
    else
        return false;
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
    char * buffer = new char[std::strlen(str)+std::strlen(rhs.str)+1];
    
    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);
    
    Mystring tmp(buffer);
    delete [] buffer;
    
    return tmp;
}

bool operator>(const Mystring &lhs, const Mystring &rhs)
{
    // Note that we cannot access data members directly if the operator is a global function
    // Alternatively, we can define such functions as friends
    return (std::strcmp(lhs.get_str(), rhs.get_str()) == 1);
}

// The * operator is defined as a friend
Mystring operator*(const Mystring &lhs, int m)
{
    if(m == 0)
        return Mystring();
        
    char * buffer = new char[std::strlen(lhs.str) * m + 1];
    
    std::strcpy(buffer, lhs.str);
    
    for(int i = 0; i < m-1; i++)
        std::strcat(buffer, lhs.str);
        
    Mystring tmp(buffer);
    
    delete [] buffer;
    
    return tmp;    
}

std::ostream & operator<<(std::ostream &os, const Mystring &obj)
{
    os << obj.str;

    return os;
}

std::istream & operator>>(std::istream &is, Mystring &obj)
{
    char * buffer = new char[1000]; // 1000 is just some large number
    is >> buffer;
    obj = Mystring{buffer};
    delete [] buffer;
    
    return is;    
}