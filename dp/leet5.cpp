#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> maxpali;
        for (int i = 0; i < s.size(); ++i) {
            // for each i, identify it's odd & even case
            // even case
            if (maxpali.second < 1) {
                maxpali = pair<int, int>{i, 1};
            }
            auto r = i + 1;
            auto l = i;

            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (maxpali.second < r - l + 1)
                    maxpali = pair<int, int>{l, r - l + 1};
                --l;
                ++r;
            }
            // odd case
            r = i + 1;
            l = i - 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (maxpali.second < r - l + 1) {
                    maxpali = pair<int, int>{l, r - l + 1};
                }
                --l;
                ++r;
            }
        }
        return s.substr(maxpali.first, maxpali.second);
    }
};

int main() {
    Solution s;
    auto x = s.longestPalindrome("aaabaaaa");
    cout << x;
}