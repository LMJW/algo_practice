#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            if (i < 4) {
                dp[i] = i - 1;
            } else {
                int pivot = (i - 1) - 2;
                int left = dp[pivot - 1];
                int right = (i - 1);
                dp[i] = pivot + max(left, right);
            }
        }
        cout << "  ";
        int i = 0;
        for (auto e : dp) {
            cout << i << " ";
            ++i;
        }
        cout << "\n";
        for (auto e : dp) {
            cout << e << " ";
        }
        cout << "\n";
        return dp[n];
    }
};

int main() {
    Solution().getMoneyAmount(21);
}