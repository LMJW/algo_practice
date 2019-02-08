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
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return divideconq(dp, 1, n);
    }

    int divideconq(vector<vector<int>>& dp, int start, int end) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] > -1) {
            return dp[start][end];
        }
        int res = numeric_limits<int>::max();
        for (int i = start; i <= end; ++i) {
            int left = divideconq(dp, start, i - 1);
            int right = divideconq(dp, i + 1, end);
            int cur = i + max(left, right);
            if (res > cur) {
                res = cur;
            }
        }
        dp[start][end] = res;

        return res;
    }
};

int main() {
    int x = Solution().getMoneyAmount(100);
    cout << x << endl;
}