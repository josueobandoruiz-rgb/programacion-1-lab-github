#pragma once
#include "Pokemon.h"

class Battle {
private:
    Pokemon& _pokemon1;
    Pokemon& _pokemon2;

public:
    Battle(Pokemon& pokemon1, Pokemon& pokemon2);
    void start();
};
