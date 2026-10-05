	int result = 0;
	for(int i = 0; i < arrSize; i++) {
		result = result ^ arr[i];
	}
	return result;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cout << getOddOccurrence(arr, N) << endl;
	}
	return 0;
}
<|endoftext|>