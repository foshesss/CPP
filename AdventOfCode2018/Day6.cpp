#include <iostream>

using namespace std;

int Day6P1() {

    /*
    Thought process:
        - Fill in as points plotted

            . . . . .
            . . . . .
            . . . . .
            . . . . .
            . . . . .

        - insert A at (1,1)

            A A A A A
            A A A A A
            A A A A A
            A A A A A
            A A A A A

        - insert B at (3, 3)

            A A A A .
            A A A . B
            A A . B B
            A . B B B
            . B B B B

        - so on

        at the end, run through entire graph, using a map to find how many of each letter.
        pretty brute-forcey, but the only thing i can think of right out the gate.

        i think the best solution would somehow be updating areas as points are added.
        (areas know how many plots they're taking up)
    */

   // until tomorrow, 2/27/22 (3:41am)

    return -1;
}

int main() {
    cout << Day6P1() << endl;
    return 0;
}