	int m = testList[0].size();
	int count = 0;
	int result = testList[0][0];
	while (count < n-1) {
		count++;
		m--;
	}
	while (count < n-1) {
		count++;
		m--;
	}
	while (count < m) {
		count++;
		result = max(result, testList[0][count]);
	}
	return result;
}
<|endoftext|>