#ifndef ENTITY_H
#define ENTITY_H

/*
[RPG]
-[Entity.cpp]---------------
    The parent class for all entities within the RPG. Each entity will always have
    three stats (Attack, Health, MaxHealth).

[OBJECT][Entity]:
    [Members]:
        atk:            [int] - 5 by default
        health:         [int]
        max_health:     [int] - 25 by default
        dead:           [bool] - false by default

    [Getters]:
        Entity::IsDead() - [bool] - returns if an Entity is dead.
        Entity::GetAtkStat() - [int] - returns attack stat of an Entity.

    [Public Methods]:
        Entity(int atk, int health) - [Entity] - Constructor for Entity.
            atk:        [int]
            health:     [int]
            @ret:       [Entity]

        ReceiveDamage(Entity* sender) - [bool] - returns boolean for if entity dies on this
            dmg:        [int]
            @ret:       [bool]

    [Virutal Methods]:
        Attack(Entity* target) - [bool] - returns if target dies D:
            target:     [Entity]
            @ret:       [bool]
        
        Died(Entity* killer) - [void] - unique died function
        
*/

class Entity {
    private:
        int atk;
        int health;
        int max_health;
        bool dead;

        virtual bool Died(Entity*);

    public:
        Entity(int, int);

        // Getters
        int GetAtkStat();
        bool IsDead();

        // Operations
        bool ReceiveDamage(Entity*); // all receive the same

        // Subclass funtions
        virtual bool Attack(Entity*);
};

#endif