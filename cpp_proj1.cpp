#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 1;
    int b = 2;

    for (int i = 0; i < 10; i++) {
        a++;
    }

    cout << a << "\n";
    cout << b << "\n";
    cout << "Sum: " << add(a, b) << "\n";
}