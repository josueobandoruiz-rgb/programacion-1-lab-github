#include <iostream>
#include <string>
#include <cstdlib> // Para rand() y srand()
#include <ctime> // Para time()
#include <conio.h> // Para getch()
#include <iomanip> // para setw, left, right
using namespace std;

// Clase Pokemon para representar cada criatura
class Pokemon {
private:
	int _health;  // Salud del Pokémon
	int _attack;  // Ataque máximo
	string _name; // Nombre del Pokémon
	
public:
	// Constructor vacío
	Pokemon() : _name("NAT"), _health(0), _attack(0) {}
	
	
	// Constructor con parámetros para inicializar atributos
	Pokemon(string name, int health, int attack)
		: _name(name), _health(health), _attack(attack) {}
	
	//Getters
	string getName() { return _name; }
	int getHealth() { return _health; }
	int getAttack() { return _attack; }
	
	// Función para recibir daño (sin que la salud sea negativa)
	void takeDamage(int damage) {
		_health -= damage;
		if (_health < 0)
			_health = 0;
	}
	
	// Función para curar al Pokemón
	void heal(int amount) {
		_health += amount;
		if (_health > 100) _health = 100; // Vida máxima 100
	}
};


	// Mostrar estadísticas del Pokémon
	void showPokemons(Pokemon pokemons[], int size, bool showStats = false) {
	cout << "\n\t    Lista de Pokemones:\n"<<endl;
	
	// Encabezados con bordes de columna (títulos)
	cout << left << setw(4) << "#" << "|" 
		<< setw(15) << "     Nombre";
	if (showStats) {
		cout << "|" << setw(8) << "   HP"
			<< "|" << setw(8) << "  ATK";
	}
	cout << "|\n";
	
	// Línea separadora de tabla (filas)
	cout << string(4, '-') << "+" 
		<< string(15, '-') ;
	if (showStats) {
		cout << "+" << string(8, '-') 
			<< "+" << string(8, '-');
	}
	cout << "+\n";
	
	// Filas de datos con columnas
	for (int i = 0; i < size; i++) {
		cout << left << setw(4) << (to_string(i + 1) + ".") << "|"
			<< setw(15) <<  pokemons[i].getName();
		if (showStats) {
			cout << "|" << setw(8) <<pokemons[i].getHealth()
				 << "|"  << setw(8) <<pokemons[i].getAttack();
		}
		cout << "|\n";
	}
	
	// Línea final de la tabla
	cout << string(4, '-') << "+" 
		<< string(15, '-');
	if (showStats) {
		cout << "+" << string(8, '-') 
			<< "+" << string(8, '-');
	}
	cout << "+\n";
}


// Clase Battle para manejar batalla entre Pokémones
class Battle {
	

private:
	Pokemon& _pokemon1;
	Pokemon& _pokemon2;
	
	
// Constructor para pelea entre 2 Pokemones	
public:
	Battle(Pokemon& pokemon1, Pokemon& pokemon2)
		: _pokemon1(pokemon1), _pokemon2(pokemon2) {}
	
	// Método para iniciar batalla
	void start() {
		cout << "\n Battle between " << _pokemon1.getName()
			<< " and " << _pokemon2.getName() << " begins! \n"<<endl;
		
		while (_pokemon1.getHealth() > 0 && _pokemon2.getHealth() > 0) {
			// Turno para el ataque del primer Pokémon
			int damage1 = rand() % (_pokemon1.getAttack() + 1);//rand() para generar el daño aleatorio
			_pokemon2.takeDamage(damage1);
			cout <<"\n"<< _pokemon1.getName() << " attacks with " << damage1
				<< " damage. \t" << _pokemon2.getName() << " HP: "
				<< _pokemon2.getHealth() << endl <<endl;
			cout << "==================================" <<endl;
			cout << "Presiona una tecla para continuar..."<<endl<<endl;
			getch();
			
			if (_pokemon2.getHealth() <= 0) break;
			
			// Turno para el ataque del segundo Pokémon
			int damage2 = rand() % (_pokemon2.getAttack() + 1);//rand() para generar el daño aleatorio
			_pokemon1.takeDamage(damage2);
			cout << "\n" <<_pokemon2.getName() << " attacks with " << damage2
				<< " damage. \t" << _pokemon1.getName() << " HP: "
				<< _pokemon1.getHealth() << endl <<endl;
			cout << "=================================="<< endl;
			cout << "Presiona una tecla para continuar..."<<endl<<endl;
			getch();
		}
		// Mostrar resultado de la Batalla
		if (_pokemon1.getHealth() <= 0 && _pokemon2.getHealth() <= 0)
			cout << "\n \tIt's a draw!\n";
		else if (_pokemon1.getHealth() <= 0)
			cout << "\n \tVictory \n" << _pokemon2.getName() << " wins the battle!\n";
		else
			cout << "\n\tVictory \n" << _pokemon1.getName() << " wins the battle!\n";
	}
};

int main() {
	srand(time(NULL)); // Semilla de aleatoriedad
	
	//Instancias Creadas
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
			
			//Validar que sea correcta la entrada
			if (p1 < 1 || p1 > 3 || p2 < 1 || p2 > 3 || p1 == p2) {
				cout << "Seleccion invalida.\n";
				system("pause");
				system("cls");
				break;
			}
			//Crear Batalla y empezar
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
			cout << "\n\n\n\t\t\t\t\t ¡Vuelve Pronto, Maestro Pokémon!"<<endl<<endl<<endl;
			cout <<"\n\t\t\t\t\t\tSaliendo del programa...\n\n\n"<<endl;
			break;
			
		default:
			cout << "Opcion invalida.\n";
			getch();
			system("cls");
		}
	} while (opcion != 4);
	
	return 0;
}
