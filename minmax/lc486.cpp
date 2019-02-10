#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return minmax(nums, 0, nums.size() - 1, true, 0, 0);
    }

    /// @pram player indicate will player is moving; true-> player1 , false ->
    /// player2
    /// @pram lo, hi inidicate which two nums that current player can take
    /// @pram ps_1, ps_2 indicate the player score
    bool minmax(vector<int>& nums,
                int lo,
                int hi,
                bool player,
                int ps_1,
                int ps_2) {
        bool res;
        if (lo == hi) {
            if (player) {
                ps_1 += nums[lo];
            } else {
                ps_2 += nums[lo];
            }
            res = ps_1 >= ps_2;
        } else {
            /// player has two moves, the lo move or high move
            /// as long as one move wins, this player win
            bool lores, hires;
            if (player) {
                lores =
                    minmax(nums, lo + 1, hi, !player, ps_1 + nums[lo], ps_2);
                hires =
                    minmax(nums, lo, hi - 1, !player, ps_1 + nums[hi], ps_2);
            } else {
                lores =
                    minmax(nums, lo + 1, hi, !player, ps_1, ps_2 + nums[lo]);
                hires =
                    minmax(nums, lo, hi - 1, !player, ps_1, ps_2 + nums[hi]);
            }

            if (player) {
                res = lores || hires;
            } else {
                res = lores && hires;
            }
        }
        return res;
    }
};

int main() {
    vector<int> arr = {1, 5, 2};
    int x = Solution().PredictTheWinner(arr);
    cout << x << "\n";
}