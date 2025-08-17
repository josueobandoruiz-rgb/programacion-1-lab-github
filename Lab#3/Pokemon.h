#pragma once
#include <string>
using namespace std;

class Pokemon {
private:
    int _health;
    int _attack;
    string _name;

public:
    Pokemon();
    Pokemon(string name, int health, int attack);

    // Getters
    string getName();
    int getHealth();
    int getAttack();

    // Métodos
    void takeDamage(int damage);
    void heal(int amount);
};
