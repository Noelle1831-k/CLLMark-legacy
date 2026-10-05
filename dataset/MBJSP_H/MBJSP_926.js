function rencontresNumber(n, m) {
	let binomial = (n, k) => {
		if (k == 0 || k == n) {
			return 1
		}
		return (binomial(n - 1, k - 1) 
		+ binomial(n - 1, k)) 
	}

	if (n == 0 && m == 0) {
		return 1
	}
	if (n == 1 && m == 0) {
		return 0
	}
	if (m == 0) {
		return ((n - 1) * (rencontresNumber(n - 1, 0) + rencontresNumber(n - 2, 0)))
	}

	return binomial(n, m) * rencontresNumber(n - m, 0)
}
