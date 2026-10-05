	int count_0 = 0;
	int count_1 = 0;
	int count_2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) count_0++;
		else if (arr[i] == 1) count_1++;
		else count_2++;
	}
	vector<int> res(n, 0);
	for (int i = 0; i < count_0; i++) {
		res[i] = 0;
	}
	for (int i = 0; i < count_1; i++) {
		res[i + count_0] = 1;
	}
	for (int i = 0; i < count_2; i++) {
		res[i + count_0 + count_1] = 2;
	}
	return res;
}
int main() {
	sortByDnf(vector<int>{1, 2, 0, 1, 0, 1, 2, 1, 1}, 9);
	sortByDnf(vector<int>{1, 0, 0, 1, 2, 1, 2, 2, 1, 0}, 10);
	sortByDnf(vector<int>{2, 2, 1, 0, 0, 0, 1, 1, 2, 1}, 10);
}
<|endoftext|>