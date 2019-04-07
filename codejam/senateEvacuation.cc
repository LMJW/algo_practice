#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct senateparty {
    char party;
    int num;
    bool operator<(const senateparty& p) { return num < p.num; }
    senateparty(int idx, int n) : party('A' + idx), num(n) {}
};

string evacuate(priority_queue<senateparty>& ps, int total) {
    // determine 1 or 2 senate
    while (ps.size() > 0) {
    }
    return "";
}

int main() {
    // num of tests
    int t;
    cin >> t;
    int idx = 0;
    while (idx <= t) {
        ++idx;
        int n;
        int total = 0;
        cin >> n;
        priority_queue<senateparty> ps;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            ps.push(senateparty(i, tmp));
            total += tmp;
        }
        // ------------
    }
}