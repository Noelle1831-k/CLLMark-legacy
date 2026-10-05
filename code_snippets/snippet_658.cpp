	vector<int> res;
	map<int, int> lMap = {};
	for (int i = 0; i < l1.size(); i++) {
		lMap[l1[i]] = lMap[l1[i]] + 1;
	}
	for (int i = 0; i < l2.size(); i++) {
		lMap[l2[i]] = lMap[l2[i]] + 1;
	}
	for (int i = 0; i < l3.size(); i++) {
		lMap[l3[i]] = lMap[l3[i]] + 1;
	}
	for (const auto [key, value] : lMap) {
		if (value == 3) {
			res.push_back(key);
		}
	}
	return res;
}
int main() {
	vector<int> l1;
	vector<int> l2;
	vector<int> l3;
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l2.push_back(0);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(6);
	l2.push_back(5);
	l3.push_back(0);
	l3.push_back(1);
	l3.push_back(2);
	l3.push_back(3);
	l3.push_back(4);
	l3.push_back(5);
	l3.push_back(7);
	vector<int> res = extractIndexList(l1, l2, l3);
	for (const auto e : res) {
		cout << e << ", ";
	}
	cout << endl;
}
<|endoftext|>