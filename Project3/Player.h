#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

using namespace std;

class Player : public Entity {
    private:

    public:
        Player(int, int);
        bool AddItemToInventory();
        bool RemoveItemFromInventory(int);

        virtual bool Attack(Entity*);
        virtual bool Died(Entity*);
};

#endif