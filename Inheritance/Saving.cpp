#include"Saving.h"
#include<iostream>

Saving::Saving(double b, double r) : Account{b}, rate{r}
{
    std::cout << "Saving Constructor\n";
}

Saving::~Saving()
{
    std::cout << "Saving Destructor\n";
}

void Saving::deposit(double x)
{
    //this.deposit(x);
}

double Saving::get_balance() const
{
    return Account::get_balance();
}

Saving & Saving::operator=(const Saving &rhs)
{
    std::cout << "Saving operator =";
    if (this == &rhs)
        return *this;
    else {
        Account::operator=(rhs); // assigns base part
        this->rate = rhs.rate;
    }
    return *this;
    
}

std::ostream & operator<<(std::ostream & os, const Saving & acc)
{
    os << "Saving Account Balance: " << acc.get_balance() << std::endl;
    os << "Interest Rate: " << acc.rate << std::endl;
    return os;
}