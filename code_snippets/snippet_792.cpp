	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			res.push_back(i);
		}
	}
	return res;
}
int main() {
	int n = 8;
	vector<int> res = luckyNum(n);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>