#include "MyLib.h"
#include <iostream>

Account::Account()
{
    std::cout << "Default Constructor called\n";
    name = "None";
    balance = 0.0;
}

Account::Account(std::string n, double b)
{
    std::cout << "Constructor with arguments\n";
    name = n;
    balance = b;
}

double Account::get_balance()
{
    return balance;
}

void Account::set_balance(double b)
{
    balance = b;
}

// Using initialization lists in constructors
//Player::Player() : name {"None"}, health {0}, xp {0} {}
//
//Player::Player(std::string name_val) : 
//name{name_val}, health{0}, xp{0} {}
//
//Player::Player(std::string name_val, int health_val, int xp_val) :
//name{name_val}, health{health_val}, xp{xp_val} {}


// We can also use delegated construction

Player::Player(std::string name_val, int health_val, int xp_val) :
name{name_val}, health{health_val}, xp{xp_val} {}

// This default constructor delegates the initializtion to the previous constructor (the most general one)
// Note that the order of values must follow the order of variables in the class declaration, i.e.:
// None goes to name since it is the first data member
// The first zero goes to health and the last zero goes to xp
Player::Player() : Player { "None", 0, 0} {}

Player::Player(std::string name_val) : Player {name_val, 0, 0} {}

Player::Player(Player const & from) : Player{from.name, from.health, from.xp} { std::cout << "copying\n";}
