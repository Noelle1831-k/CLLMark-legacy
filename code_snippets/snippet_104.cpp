	map<int, int> m;
	for (int i = 0; i < nestedlist.size(); i++) {
		for (int j = 0; j < nestedlist[i].size(); j++) {
			m[nestedlist[i][j]]++;
		}
	}
	vector<int> res;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == nestedlist.size()) res.push_back(it->first);
	}
	return res;
}
<|endoftext|>