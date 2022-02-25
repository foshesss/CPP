#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include "Entity.h"

using namespace std;

/*
[PRACTICE]
-[cpp_proj1.cpp]---------------
    This is sort of my introduction to C++. To be honest, I am only
    really learning because I know it's a super useful language, but alsooo
    I saw that you can embed Lua into it, which looks super interesting.
*/

int main() {
    Entity player(10, 50);
    Entity enemy(5, 25);

    bool battle_decided = false;
    string last_attacker;

    // entity cannot attack itself :rolling_eyes_emoji:
    player.Attack(&player);

    // generate random seed
    srand(time(NULL));

    // continue battling to the death.
    while (battle_decided == false) {
        int attacker = rand() % 2 + 1;

        if (attacker == 1) {
            battle_decided = player.Attack(&enemy);
            last_attacker = "PLAYER"; 
        } else {
            battle_decided = enemy.Attack(&player);
            last_attacker = "ENEMY";
        }

       cout << last_attacker << " ATTACKS!\n";
    }

    cout << last_attacker << " WINS!\n";
    enemy.PrintStats();
    player.PrintStats();
}