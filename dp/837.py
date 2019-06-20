class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        dp = [0] * (K + W)
        S = 0
        for i in range(K + W - 1, K - 1, -1):
            if i > N:
                dp[i] = 0
            else:
                dp[i] = 1
                S += 1

        dp[K - 1] = S / W
        for i in range(K - 2, -1, -1):
            if i + W + 1 >= len(dp):
                t = 0
            else:
                t = dp[i + W + 1]
            dp[i] = dp[i + 1] * (1 + 1 / W) + t / W

        return dp[0]