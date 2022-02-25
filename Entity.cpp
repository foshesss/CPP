#include <iostream>
#include "Entity.h"

using namespace std;

/*
[PRACTICE]
-[Entity.cpp]---------------

[OBJECT][Entity]:
    [Members]:
        _dmg:           [int]
        _health:        [int]
        _max_health:    [int]

    [Methods]:
        Entity::Entity(int dmg, int health) - [Entity] - creates an entity
            dmg:        [int]
            health:     [int] -- sets MaxHealth to this.
            @ret:       [Entity]

        Entity::GetDamage() - [int] - returns an entity's damage (attack value)
            @ret:       [Entity]

        Entity::Attack(Entity *target); - [bool] - entity will attack a target entity
            target:     [Entity*]
            @ret:       [bool] - true if KILLED, false if not

        Entity::TakeDamage(Entity* sender) - [bool] - Entity takes damage, specified by 'dmg' argument.
            sender:     [Entity*]
            @ret:       [bool] - true if dead, false if not

        Entity::PrintStats() - [void] - print all relevant stats of an entity (dmg, health/max_health)
            @ret:       null

*/

Entity::Entity(int dmg, int health) {
    this->dmg = dmg;
    this->health = health;
    this->max_health = health;
}

// GETTERS
int Entity::GetDamage() {
    return this->dmg;
}

bool Entity::Attack(Entity *target) {
    if (target == this) { 
        cout << "CANNOT ATTACK YOURSELF! >:( \n";
        return false; 
    }

   return (*target).TakeDamage(this);
}

bool Entity::TakeDamage(Entity *sender) {
    int dmg = (*sender).GetDamage();

    if (dmg < 0) { return true; }

    this->health = max(this->health - dmg, 0);
    return (this->health == 0);
}

void Entity::PrintStats() {
    cout << "Damage: " << this->dmg << '\n';
    cout << "Health: " << this->health << "/" << this->max_health << '\n';
}