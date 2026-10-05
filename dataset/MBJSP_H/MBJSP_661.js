function maxSumOfThreeConsecutive(arr, n) {
	let sums = [0, 0, 0];

	if (n >= 1) {
		sums[0] = arr[0];
	}

	if (n >= 2) {
		sums[1] = arr[0] + arr[1];
	}

	if (n > 2) {
		sums[2] = Math.max(sums[1], Math.max(arr[1] + arr[2], arr[0] + arr[2]));
	}

	for (let i = 3; i < n; i++) {
		sums[i] = Math.max(
			Math.max(sums[i - 1], sums[i - 2] + arr[i]),
			arr[i] + arr[i - 1] + sums[i - 3]
		);
	}

	return sums[n - 1];
}
