#include <iostream>
#include <string>

using namespace std;

string find_path(int n, string p) {
    string res;
    for (auto iter = p.begin(); iter != p.end(); ++iter) {
        if (*iter == 'S') {
            res.push_back('E');
        } else {
            res.push_back('S');
        }
    }
    return res;
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n = 0;
        string p;
        cin >> n;
        cin >> p;
        auto np = find_path(n, p);
        cout << "Case #" << i << ": " << np << endl;
    }
}