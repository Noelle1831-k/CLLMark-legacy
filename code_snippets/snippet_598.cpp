	vector<int> mul;
	map<int, int> m;
	for (int i = 0; i < nums1.size(); i++) {
		m[nums1[i]] = nums2[i];
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		mul.push_back(it->first * it->second);
	}
	return mul;
}
int main() {
	vector<int> A{1, 2, 3};
	vector<int> B{4, 5, 6};
	vector<int> mul = mulList(A, B);
	for (auto it = mul.begin(); it != mul.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>