#include <iostream>

using namespace std;

void number_split(int n, int& a, int& b) {
    int c = 1;
    while (n > 0) {
        int k = n / 10;
        int r = n - k * 10;
        if (r == 4) {
            a += 2 * c;
            b += 2 * c;
        } else {
            a += c * r;
        }
        n = k;
        c *= 10;
    }
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n = 0;
        cin >> n;
        int a = 0;
        int b = 0;
        number_split(n, a, b);
        cout << "Case #" << i << ": " << a << " " << b << endl;
    }
}