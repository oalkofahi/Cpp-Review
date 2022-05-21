#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include<iostream>

class Mystring {
    
    friend Mystring operator*(const Mystring &lhs, int m);
    friend std::ostream & operator<<(std::ostream &os, const Mystring &obj);
    friend std::istream & operator>>(std::istream &is, Mystring &obj);
private:
    char *str;
    
public:
    Mystring();
    Mystring(const char *);
    Mystring(const Mystring & source);
    ~Mystring();
    void display() const;
    int length() const;
    const char * get_str() const;  
    // Assignment operator
    Mystring & operator=(const Mystring &rhs); // Copy assignment
    Mystring & operator=(Mystring &&rhs); // Move assignment: rhs cannot be const since we need to modify any ptr to NULL
    
    // Unary operators: Don't take parameters
    // negation: we want to use this operator to convert the string to lower case
    Mystring operator-() const;
    
    // Binary operators: takes one parameter = RHS (the other operator is the object itself = LHS)
    // Equality operator
    bool operator==(const Mystring &rhs) const;
    
    // Addition operators
    Mystring operator+(const Mystring &rhs) const;
};

bool operator>(const Mystring &lhs, const Mystring &rhs);

Mystring operator*(const Mystring &lhs, int m);

#endif 