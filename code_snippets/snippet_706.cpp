	map<int, vector<int>> t1;
	map<int, vector<int>> t2;
	for (auto x : testList1) {
		t1[x[0]] = x;
	}
	for (auto x : testList2) {
		t2[x[0]] = x;
	}
	map<int, vector<int>> t1copy = t1;
	map<int, vector<int>> t2copy = t2;
	for (auto x : t1) {
		if (t2.find(x.first) == t2.end()) {
			return false;
		}
		else if (t1[x.first][1] != t2[x.first][1]) {
			return false;
		}
		else {
			t1copy.erase(x.first);
			t2copy.erase(x.first);
		}
	}
	if (t1copy.size() != 0 && t2copy.size() != 0) {
		return false;
	}
	return true;
}
<|endoftext|>