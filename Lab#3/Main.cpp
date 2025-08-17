#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Pokemon.h"
#include "Battle.h"
#include "utils.h"
using namespace std;

int main() {
    srand(time(NULL));

    Pokemon pokemons[3] = {
        Pokemon("Pikachu", 100, 15),
        Pokemon("Charmander", 90, 20),
        Pokemon("Bulbasaur", 110, 10)
    };

    int opcion;
    do {
        cout << "\n====== MENU DE OPCIONES ======\n";
        cout << "1. Mostrar Pokemones disponibles\n";
        cout << "2. Elegir Pokemones para luchar\n";
        cout << "3. Curar un Pokemon\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            showPokemons(pokemons, 3, true);
            system("pause");
            system("cls");
            break;

        case 2: {
            int p1, p2;
            showPokemons(pokemons, 3, true);
            cout << "Seleccione el número del primer Pokemon: ";
            cin >> p1;
            cout << "Seleccione el número del segundo Pokemon: ";
            cin >> p2;
            system("cls");

            if (p1 < 1 || p1 > 3 || p2 < 1 || p2 > 3 || p1 == p2) {
                cout << "Seleccion invalida.\n";
                system("pause");
                system("cls");
                break;
            }
            Battle battle(pokemons[p1 - 1], pokemons[p2 - 1]);
            battle.start();

            system("pause");
            system("cls");
            break;
        }

        case 3: {
            int p;
            showPokemons(pokemons, 3, true);
            cout << "Seleccione el Pokemon que desea curar: ";
            cin >> p;
            if (p >= 1 && p <= 3) {
                pokemons[p - 1].heal(20);
                cout << pokemons[p - 1].getName() << " ha sido curado en 20 HP.\n";
            } else {
                cout << "Seleccion invalida.\n";
            }
            system("pause");
            system("cls");
            break;
        }

        case 4:
            cout << "\n\n\n\t\t\t\t\t ¡Vuelve Pronto, Maestro Pokémon!" << endl << endl << endl;
            cout << "\n\t\t\t\t\t\tSaliendo del programa...\n\n\n" << endl;
            break;

        default:
            cout << "Opcion invalida.\n";
            getch();
            system("cls");
        }
    } while (opcion != 4);

    return 0;
}
