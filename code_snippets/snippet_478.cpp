	int count = 0;
	for (int i = 0; i < n-1; i++) {
		string firstNumber = to_string(i);
		string secondNumber = to_string(i+1);
		count += hammingDistance(firstNumber, secondNumber);
	}
	return count;
}
int hammingDistance(string first, string second) {
	int count = 0;
	for (int i = 0; i < first.length(); i++) {
		if (first[i] != second[i]) {
			count++;
		}
	}
	return count;
}
int main() {
	int n = 4;
	cout << totalHammingDistance(n);
	return 0;
}
<|endoftext|>