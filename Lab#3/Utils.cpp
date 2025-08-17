#include <iostream>
#include <iomanip>
#include "utils.h"
using namespace std;

void showPokemons(Pokemon pokemons[], int size, bool showStats) {
    cout << "\n\t    Lista de Pokemones:\n" << endl;
    cout << left << setw(4) << "#" << "|" 
         << setw(15) << "     Nombre";
    if (showStats) {
        cout << "|" << setw(8) << "   HP"
             << "|" << setw(8) << "  ATK";
    }
    cout << "|\n";

    cout << string(4, '-') << "+" << string(15, '-');
    if (showStats) {
        cout << "+" << string(8, '-') << "+" << string(8, '-');
    }
    cout << "+\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(4) << (to_string(i + 1) + ".") << "|"
             << setw(15) << pokemons[i].getName();
        if (showStats) {
            cout << "|" << setw(8) << pokemons[i].getHealth()
                 << "|" << setw(8) << pokemons[i].getAttack();
        }
        cout << "|\n";
    }

    cout << string(4, '-') << "+" << string(15, '-');
    if (showStats) {
        cout << "+" << string(8, '-') << "+" << string(8, '-');
    }
    cout << "+\n";
}
