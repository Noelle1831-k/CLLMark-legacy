	int cursum = 0, maxsum = a[0];
	for (int i = 0; i < size; i++) {
		cursum += a[i];
		if (cursum > maxsum) maxsum = cursum;
		if (cursum < 0) cursum = 0;
	}
	return maxsum;
}
int main() {
	vector<int> a;
	int size;
	while (1) {
		scanf("%d", &size);
		if (size == 0) break;
		a.clear();
		for (int i = 0; i < size; i++) {
			int tmp;
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		printf("%d\n", maxSubArraySum(a, size));
	}
	return 0;
}
<|endoftext|>