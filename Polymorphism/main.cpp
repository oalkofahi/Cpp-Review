/*
 * Polymorphism is allowed through:
 * - Inheritance
 * - Base class pointers or references
 * - Virtual functions
 * 
 * Redefined functions in derived classes will be bound statically (compile time)
 * 
 * Overridden functions are bound dynamically (run time)
 * 
 * Virtual functions are overriden
 * 
 * Allows us to think abstractly in terms of the base class, 
 * -- but behavior will be customized based on derived class type
 * 
 * If a class has a VIRTUAL function, we should provide a VIRTUAL DESTRUCTOR (just precede with virtual)
 * 
 * The keyword "override" to override virtual functions will make sure that you are overriding 
 * the virtual function that you intended to override
 * 
 * The keyword "final":
 * - If used at class level ==> prevents derrivation from class
 * - If used at method level ==> prevents virtual methods from being overriden in derived classes
 */
 
#include <iostream>

using namespace std;
 
class Account {
private:
    double balance;
public:
    Account(double x = 0) : balance{x} {}
    void withdraw(double a) {
        cout << "Account Withdraw\n";
        balance -= a;
    }
    void display() const
    {
        cout << "Account Balance: " << balance << endl;
    }
    
    virtual void display2() const
    {
        cout << "Account Balance: " << balance << endl;
    }
    
    double get_balance() const {return balance;}
    
    virtual ~Account() {cout << "Account Destructor of " << balance << endl;}
};

// Note that adding "final" here means Saving cannot be derrived from
// class Saving final : public Account { 
class Saving : public Account { 
private:
    double rate;
public:
    Saving(double b, double r) : Account{b}, rate{r} {}
    // redefines display in derived class
    void display() const 
    {
        cout << "Saving Account Balance: " << Account::get_balance() << endl;
        cout << "Rate: " << rate << endl;
    }
    
    // Overrides display2
    // Note that specifying virtual here is not necessary, but it is a good practice
    // Note also that "final" here means that derrived classes from Saving cannot override this method
    virtual void display2() const override final
    {
        cout << "Saving Account Balance: " << Account::get_balance() << endl;
        cout << "Rate: " << rate << endl;
    }
    
    virtual ~Saving() {cout << "Saving Account Destructor of " << Account::get_balance() << endl;}
  
};

void print(const Account & acc)
{
    acc.display();
}

void print2(const Account & acc)
{
    acc.display2();
}


int main()
{
    Account a(1000);
    Saving s(2000, 0.05);
    
    Account * ptr = new Saving(3000, 0.06);
    
    // Static binding
    ptr->display2(); // will call Account display()
    delete ptr; // will call the destructor of Saving because of virtual destructors
    
    print(a); // will call Account display()
    print(s); // will call Account display()
    
    // Dynamic binding because print2 calls display2 which is a VIRTUAL function
    print2(a); // will call Account display()
    print2(s); // will call Saving display()
    return 0;
}