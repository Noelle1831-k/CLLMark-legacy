function findCloset(a, b, c, p, q, r) {
	let [i, j, k] = [0, 0, 0];
	let diff = Number.MAX_SAFE_INTEGER;
	let res = [];
	while (i < p && j < q && k < r) {
		const a_minimum = Math.min(a[i], Math.min(b[j], c[k]));
		const a_maximum = Math.max(a[i], Math.max(b[j], c[k]));
		if (a_maximum - a_minimum < diff) {
			res = [a[i], b[j], c[k]];
			diff = a_maximum - a_minimum;
		}
		if (a[i] == a_minimum) i++;
		if (b[j] == a_minimum) j++;
		if (c[k] == a_minimum) k++;
	}
	return res;
}
