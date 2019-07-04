#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        unordered_map<char, int> dict{};
        for (auto let : licensePlate)
        {
            if (isalpha(let))
            {
                auto l = tolower(let);
                // dict.find(l) != dict.end() ? dict[l]++ : dict[l] = 1;
                dict[l]++;
            }
        }

        string ans(1000, 'z');

        for (auto w : words)
        {
            if (w.size() > ans.size())
                continue;
            unordered_map<char, int> x{};
            for (auto let : w)
            {
                if (isalpha(let))
                {
                    auto l = tolower(let);
                    // x.find(l) != x.end() ? x[l]++ : x[l] = 1;
                    x[l]++;
                }
            }

            bool ok = true;
            for (auto it = dict.begin(); it != dict.end(); it++)
            {
                auto key = it->first;
                auto val = it->second;
                ok = ok && (x[key] >= val);
            }
            if (ok)
            {
                if (w.size() < ans.size())
                {
                    ans = w;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string lp1 = "1s3 PSt";
    vector<string> w1 = {"step", "steps", "stripe", "stepple"};
    /// expect "steps"
    cout << s.shortestCompletingWord(lp1, w1) << endl;

    string lp2 = "1s3 456";
    vector<string> w2 = {"looks", "pest", "stew", "show"};
    /// expect "pest"
    cout << s.shortestCompletingWord(lp2, w2) << endl;
}