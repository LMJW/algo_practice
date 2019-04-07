#include <iostream>

int main() {
    int m = 3;
    int total = 0;
    while (m < 1000) {
        total += m;
        m += 3;
    }
    m = 5;
    while (m < 1000) {
        if (m % 3 != 0) {
            total += m;
        }
        m += 5;
    }
    std::cout << total << std::endl;
}