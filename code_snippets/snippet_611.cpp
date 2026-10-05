	for (int i = 0; i < testTup2.size(); i++) {
		if (testTup2[i] > testTup1[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	cout << checkGreater(vector<int>{10, 4, 5}, vector<int>{13, 5, 18}) << endl;
	cout << checkGreater(vector<int>{1, 2, 3}, vector<int>{2, 1, 4}) << endl;
	cout << checkGreater(vector<int>{4, 5, 6}, vector<int>{5, 6, 7}) << endl;
	return 0;
}
<|endoftext|>