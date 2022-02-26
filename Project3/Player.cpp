#include <iostream>
#include "Entity.h"
#include "Player.h"

using namespace std;

Player::Player(int atk, int dmg) : Entity(atk, dmg) {}

bool Player::Attack(Entity* victim) {
    bool eliminated = (*victim).ReceiveDamage(this);

    if (eliminated == true) {
        (*victim)::Died(this);
    }

    return false;
}

bool Player::Died(Entity *killer) {
    // if (Entity::Died(killer) == false) { 
    //     return false; 
    // }

    cout << "PLAYA DIED!\n";
    // lose part of inventory
    return true;
}
