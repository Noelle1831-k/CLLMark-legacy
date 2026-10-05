function lcsOfThree(x, y, z, m, n, o) {
	let memo = new Array(m+1).fill(new Array(n+1).fill(0));
	let maxLength = 0;

	for (let i = 1; i <= m; i++) {
		for (let j = 1; j <= n; j++) {
			for (let k = 1; k <= o; k++) {
				if (x[i-1] === y[j-1] && x[i-1] === z[k-1]) {
					memo[i][j] = memo[i-1][j-1] + 1;
					maxLength = Math.max(memo[i][j], maxLength);
				} else {
					memo[i][j] = Math.max(memo[i-1][j], memo[i][j-1]);
				}
			}
		}
	}

	return maxLength;
}
