#include <iostream>
#include <unordered_map>

using namespace std;

/*
[PRACTICE]
-[proj3.cpp]--------------
    The goal with this project is to start working with actual OOP
    principles. Reusing the original Entity class as a parent class, 
    and creating subclasses, Enemies and Players with special attributes/behaviors.

- [HIERARCHY]:
    - [Entity]
        - [Player]
            - Has an inventory
        - [Enemy]
            - Has drops (chance to drop something if slain)

    Potentially, a 'Dead' operation, which will destroy the Entity, but also
    will also have some separate action for each class. Player might drop some
    of their inventory, whereas the Enemy might drop a weapon.

    TODO:
        - Google methods to store enemy data (id-based). O(1) lookup for item stats.
        - Modify Entity to have virtual methods (methods that should be overriden).
            - Attack should be virtual (give Enemies different types of attacks)

    goodnight, 2/26/22 (4:34am)
*/

// Credit: https://www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
template<typename Base, typename T>
inline bool instanceof(const T*) {
   return is_base_of<Base, T>::value;
}

class Entity {
    private:
        int atk, health, max_health;
    
    public:
        Entity(int atk, int health) {
            this->atk = atk;
            this->health = health;
            this->max_health = health;
        };

        int GetAtkStat() {
            return this->atk;
        }

        virtual void print_stats() {
            cout << "Attack: " << this->atk << endl;
            cout << "Health: " << this->health << "/" << this->max_health << endl;
        };

        virtual void Attack(Entity*) = 0;
        virtual bool Died(Entity*) = 0;

        void TakeDamage(Entity* attacker) {
            int dmg = attacker->GetAtkStat();

            this->health = max(this->health - dmg, 0);

            if (this->health == 0) {
                this->Died(attacker);
            }
        };
};

class Player : public Entity {
    private:
        unordered_map<int, int> inventory;

    public:
        Player(int atk, int health) : Entity(atk, health) {
            this->inventory.insert(pair<int, int>(1, 1));
            this->inventory.insert(pair<int, int>(10, 5));
        };

        void print_stats() {
            cout << "----- Player stats -----" << endl;
            Entity::print_stats();
            cout << "Inventory: " << endl;
            
            // print inventory
            unordered_map<int, int>::iterator it = this->inventory.begin();
            while (it != this->inventory.end()) {
                cout << it->first << " - " << it->second << endl;
                it++;
            }
        };

        void Attack(Entity *e) {
            e->TakeDamage(this);
        };

        bool Died(Entity* _) {
            // lose inventory or something
            cout << "wow! i died!" << endl;
            return true;
        }
};

class Enemy : public Entity {
    private:
        unordered_map<int, float> drops;
            // key: item_id, val: drop_chance
    
    public:
        Enemy(int atk, int health) : Entity(atk, health) {
            // init some drops
        };

        void Attack(Entity* e) {
            e->TakeDamage(this);
        };

        bool Died(Entity* e) {

           // TODO: figure out if this is a Player. gotta be a way. OR
           // hacky way: private _tag variable, with :GetTag() method..? 

            cout << instanceof<Player>(e) << endl;

            if (instanceof<Player>(e) == true) {
                cout << "Defeated by a player!" << endl;
            } else {
                cout << "oh no! I have been defeated!" << endl;
            }
            return true;
        };
};

int main() {
    Player p1(25, 25);
    Enemy e(5, 5);

    p1.Attack(&e);
    
    return 0;
}