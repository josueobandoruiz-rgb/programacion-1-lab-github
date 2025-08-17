#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "Battle.h"
using namespace std;

Battle::Battle(Pokemon& pokemon1, Pokemon& pokemon2)
    : _pokemon1(pokemon1), _pokemon2(pokemon2) {}

void Battle::start() {
    cout << "\n Battle between " << _pokemon1.getName()
         << " and " << _pokemon2.getName() << " begins! \n" << endl;

    while (_pokemon1.getHealth() > 0 && _pokemon2.getHealth() > 0) {
        int damage1 = rand() % (_pokemon1.getAttack() + 1);
        _pokemon2.takeDamage(damage1);
        cout << "\n" << _pokemon1.getName() << " attacks with " << damage1
             << " damage. \t" << _pokemon2.getName() << " HP: "
             << _pokemon2.getHealth() << endl << endl;
        cout << "==================================" << endl;
        cout << "Presiona una tecla para continuar..." << endl << endl;
        getch();

        if (_pokemon2.getHealth() <= 0) break;

        int damage2 = rand() % (_pokemon2.getAttack() + 1);
        _pokemon1.takeDamage(damage2);
        cout << "\n" << _pokemon2.getName() << " attacks with " << damage2
             << " damage. \t" << _pokemon1.getName() << " HP: "
             << _pokemon1.getHealth() << endl << endl;
        cout << "==================================" << endl;
        cout << "Presiona una tecla para continuar..." << endl << endl;
        getch();
    }

    if (_pokemon1.getHealth() <= 0 && _pokemon2.getHealth() <= 0)
        cout << "\n \tIt's a draw!\n";
    else if (_pokemon1.getHealth() <= 0)
        cout << "\n \tVictory \n" << _pokemon2.getName() << " wins the battle!\n";
    else
        cout << "\n\tVictory \n" << _pokemon1.getName() << " wins the battle!\n";
}
