#include "Pokemon.h"

Pokemon::Pokemon() : _name("NAT"), _health(0), _attack(0) {}

Pokemon::Pokemon(string name, int health, int attack)
    : _name(name), _health(health), _attack(attack) {}

string Pokemon::getName() { return _name; }
int Pokemon::getHealth() { return _health; }
int Pokemon::getAttack() { return _attack; }

void Pokemon::takeDamage(int damage) {
    _health -= damage;
    if (_health < 0) _health = 0;
}

void Pokemon::heal(int amount) {
    _health += amount;
    if (_health > 100) _health = 100;
}
