#include <iostream>
#include "Entity.h"

using namespace std;

// Constructor
Entity::Entity(int atk, int health) {
    this->atk = atk;
    this->health = health;
    this->max_health = health;
    this->dead = false;
}

// Getters
bool Entity::IsDead() {
    return this->dead;
}

int Entity::GetAtkStat() {
    return this->atk;
}

// Standard operations
bool Entity::ReceiveDamage(Entity *sender) {
    if (Entity::IsDead() == true || (*sender).IsDead() == true) { return false; }

    int dmg = (*sender).GetAtkStat();
    this->health = max(this->health - dmg, 0);

    if (this->health == 0) {
        Entity::Died(sender);
        return true;
    }
    return false;
};

// Virtual functions
bool Entity::Died(Entity *killer) {
    if (Entity::IsDead() == true) { return false; }
    this->dead = true;

    cout << "ENTITY DIED\n";
    return true;
}

bool Entity::Attack(Entity *victim) {
    return true;
}