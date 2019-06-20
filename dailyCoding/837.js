/**
 * @param {number} N
 * @param {number} K
 * @param {number} W
 * @return {number}
 */

var new21Game = function(N, K, W) {
	let dp = Array(K + W).fill(null);
	let sum = 0;
	for (let i = K; i < K + W; i++) {
		if (i <= N) {
			dp[i] = 1;
			sum += 1;
		} else {
			dp[i] = 0;
		}
	}

	dp[K - 1] = sum / W;
	for (let i = K - 2; i >= 0; i--) {
		let t = i + 1 + W > K + W - 1 ? 0 : dp[i + W + 1] / W;
		dp[i] = dp[i + 1] * (1 + 1 / W) - t;
	}

	return dp[0];
};

let x = new21Game(21, 17, 10);
console.log(x);
