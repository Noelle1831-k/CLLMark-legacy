	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] != arr[j])
				count++;
		}
	}
	return count;
}
int main() {
	countPairs(vector<int>{1, 2, 1}, 3);
	countPairs(vector<int>{1, 1, 1, 1}, 4);
	countPairs(vector<int>{1, 2, 3, 4, 5}, 5);
}
<|endoftext|>