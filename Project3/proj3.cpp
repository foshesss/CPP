#include <iostream>
#include "Player.h"

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

    goodnight, 2/25/22 (3:09am)
*/

int main() {
    Player p1(50, 25);
    Player p2(5, 25);

    p1.Attack(&p2);
    
    return 0;
}