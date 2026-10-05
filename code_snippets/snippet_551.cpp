	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			result += arr[i] ^ arr[j];
		}
	}
	return result;
}
int main() {
	cout << pairOrSum({5, 9, 7, 6}, 4);
	return 0;
}
<|endoftext|>