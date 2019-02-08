#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

struct point {
    int x;
    int y;
    point() : x(0), y(0) {}
    point(int a, int b) : x(a), y(b) {}
    friend bool operator==(const point& p1, const point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
};

template <>
struct hash<point> {
    size_t operator()(point const& p) const noexcept {
        size_t h1 = hash<int>{}(p.x);
        size_t h2 = hash<int>{}(p.y);
        return h1 ^ (h2 << 1);
    }
};

class Solution {
public:
    /**
     * We do not know how to pick the pivot
     * we can only use brute force to pice pivot
     * The
     */
    int getMoneyAmount(int n) {
        unordered_map<point, int> dp;
        return divideconq(dp, 1, n);
    }

    int divideconq(unordered_map<point, int>& dp, int start, int end) {
        auto p = point(start, end);
        auto it = dp.find(p);
        if (it != dp.end()) {
            return it->second;
        };

        if (start >= end) {
            return 0;
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
        dp.insert({point(start, end), res});

        return res;
    }
};

int main() {
    int x = Solution().getMoneyAmount(100);
    cout << x << endl;
}