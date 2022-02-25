#ifndef ENTITY_H
#define ENTITY_H

// Players and enemies are entities. They all have health, the ability to attack, etc.

class Entity {
    private:
        int health;
        int max_health;
        int dmg;
    
    public:
        Entity(int dmg = 1, int health = 10);
        bool Attack(Entity*); // Damage another entity
        bool TakeDamage(Entity*);
        void PrintStats();
        int GetDamage();
};

#endif