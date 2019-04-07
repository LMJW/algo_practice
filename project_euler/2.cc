#include <iostream>

int fab(int n, int& sum) {
    int a = 0;
    int b = 1;
    while (b < n) {
        int t = a;
        a = b;
        b = t + a;
        if (b % 2 == 0) {
            sum += b;
        }
    }
    return b;
}

int main() {
    int total = 0;
    fab(4000000, total);
    std::cout << total << std::endl;
}