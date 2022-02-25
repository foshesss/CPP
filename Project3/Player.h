#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

using namespace std;

class Player {
    private:
        vector<int> inventory;

    public:
        Player();
        bool AddItemToInventory();
        bool RemoveItemFromInventory(int);
};

#endif PLAYER_H