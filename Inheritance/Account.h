#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include<ostream>
class Account
{
private:
    double balance;
public:
    void deposit(double amount);
    void withdraw(double amount);
    Account(double=0);
    ~Account();
    double get_balance() const;
    Account & operator=(const Account &rhs);
};

std::ostream & operator<<(std::ostream &os, const Account &a);
#endif