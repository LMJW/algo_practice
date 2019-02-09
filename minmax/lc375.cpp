#include <chrono>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;
/// actually, we do not neet to use customized the struct point to store the
/// intermediate values. We can use an array to store these values

class Solution {
public:
    /**
     * We do not know how to pick the pivot
     * we can only use brute force to pice pivot
     * The
     */
    int getMoneyAmount(int n) {
        unordered_map<int, int> dp;
        return divideconq(dp, n, 1, n);
    }
    int divideconq(unordered_map<int, int>& dp, int& n, int lo, int hi) {
        if (lo >= hi) {
            return 0;
        }
        int key = lo * n + hi;
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        int res = INT_MAX;
        for (int i = (lo + hi) / 2; i < hi; ++i) {
            int right = divideconq(dp, n, i + 1, hi);
            int cur = i + max(divideconq(dp, n, lo, i - 1),
                              divideconq(dp, n, i + 1, hi));
            if (res > cur) {
                res = cur;
            }
        }
        dp[key] = res;
        return res;
    }
};

int main() {
    auto start = chrono::system_clock::now();
    int x = Solution().getMoneyAmount(100);
    auto end = chrono::system_clock::now();
    cout << x << endl;
    cout << "Time used: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << endl;
}