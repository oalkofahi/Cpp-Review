#ifndef _MYLIB_H_
#define _MYLIB_H_

#include <string>
class Account {
private:
    double balance;
    std::string name;
public:
    Account();
    Account(std::string, double);
    void set_balance(double);
    
    double get_balance();    
};

/*
 * Constructor initialization lists allow true initialization
 * In contrast to calling the constructor and then giving values to variables that already exist
 * */

class Player {
private:
    std::string name;
    int health;
    int xp;
    
public:
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
    Player(Player const & from);
    std::string get_name() {return name;}
    
};

#endif