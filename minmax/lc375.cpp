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

    int divideconq(unordered_map<int, int>& dp, int& n, int start, int end) {
        if (start >= end) {
            return 0;
        }

        int key = start * n + end;
        auto it = dp.find(key);
        if (it != dp.end()) {
            return it->second;
        }

        int res = numeric_limits<int>::max();
        for (int i = start; i <= end; ++i) {
            int left = divideconq(dp, n, start, i - 1);
            int right = divideconq(dp, n, i + 1, end);
            int cur = i + max(left, right);
            if (res > cur) {
                res = cur;
            }
        }
        dp[key] = res;

        return res;
    }
};

int main() {
    int x = Solution().getMoneyAmount(100);
    cout << x << endl;
}