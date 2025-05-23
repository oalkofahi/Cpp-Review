#ifndef _SAVING_H
#define _SAVING_H

#include"Account.h"
#include<ostream>
class Saving : public Account
{
    friend std::ostream & operator<<(std::ostream & os, const Saving & acc);
private:
    double rate;
public:
    Saving(double = 0, double = 0.01);
    ~Saving();
    void deposit(double);
    void withdraw(double);  
    double get_balance() const;
    
    Saving & operator=(const Saving &rhs);
};

#endif