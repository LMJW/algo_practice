#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    bool stop_flag = false;

    while (t > 0 && !stop_flag) {
        --t;

        int n, a, b;
        cin >> a >> b;
        cin >> n;
        ++a;  // a is not in the range
        string response;
        bool retry_flag = true;
        while (n > 0 && retry_flag) {
            --n;
            int g = (a + b) / 2;
            cout << g << endl;
            cin >> response;
            switch (response.back()) {
                case 'T':  // CORRECT
                    retry_flag = false;
                    break;
                case 'L':  // TOO_small
                    a = g + 1;
                    break;
                case 'G':  // TOO_BIG
                    b = g - 1;
                    break;
                case 'R':  // WRONG_ANSWER
                    stop_flag = true;
                    retry_flag = false;
                    break;
            }
        }
    }
}