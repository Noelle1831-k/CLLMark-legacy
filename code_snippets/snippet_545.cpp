	while (start < end) {
		int m = start + (end - start) / 2;
		if (array[m] > m) end = m;
		else start = m + 1;
	}
	return start;
}
int main() {
	vector<int> array = {2, 3, 5, 8, 9};
	printf("The first missing number is: %d\n", findFirstMissing(array, 0, array.size() - 1));
	return 0;
}
<|endoftext|>