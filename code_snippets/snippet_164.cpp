	vector<int> res;
	for (int i = l; i <= r; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			res.push_back(i);
		}
	}
	return res;
}
int main() {
	int l, r;
	cin >> l >> r;
	vector<int> res = answer(l, r);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << (i != res.size() - 1 ? " " : "");
	}
	cout << endl;
	return 0;
}
<|endoftext|>