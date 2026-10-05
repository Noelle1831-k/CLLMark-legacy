function findWays(m) {
	var bin = 1
	for (var i = 1; i <= m / 2; i++) {
		bin = bin * (m - i + 1) / (i + 1)
	}
	return bin
}
