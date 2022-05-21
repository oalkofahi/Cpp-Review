#include"Account.h"
#include<iostream>

Account::Account(double a) : balance{a}
{
    std::cout << "Account Constructor\n";
}

Account::~Account()
{
    std::cout << "Account Destructor\n";
}

double Account::get_balance() const
{
    return balance;
}
Account & Account::operator=(const Account &rhs)
{
    std::cout << "Account operator =\n";
    if (this == &rhs)
        return *this;
    else
        this->balance = rhs.balance;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Account & acc)
{
    os << "Account Balance: " << acc.get_balance() << std::endl;
    return os;
}