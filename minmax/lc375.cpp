#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * We do not know how to pick the pivot
     * we can only use brute force to pice pivot
     * The
     */
    int getMoneyAmount(int n) { return divideconq(1, n); }

    int divideconq(int start, int end) {
        if (start >= end) {
            return 0;
        }

        int res = numeric_limits<int>::max();
        for (int i = start; i <= end; ++i) {
            int left = divideconq(start, i - 1);
            int right = divideconq(i + 1, end);
            int cur = i + max(left, right);
            if (res > cur) {
                res = cur;
            }
        }
        return res;
    }
};

int main() {
    int x = Solution().getMoneyAmount(20);
    cout << x << endl;
}