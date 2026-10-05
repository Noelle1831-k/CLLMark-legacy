function lobbNum(n, m) {
	var binomial_coeff = function(n, k) {
		var c = 1;
		for (var i = 0; i < k; i++) {
			c = c * (n - i) / (k - i);
		}
		return c;
	}

	return (((2 * m + 1) * binomial_coeff(2 * n, m + n)) / (m + n + 1));
}
