	string ret = "[";
	testList.sort([](vector<int> &v1, vector<int> &v2) {
		int i1 = v1.size();
		for (int i = 0; i < v1.size(); i++) {
			i1 += to_string(v1[i]).size();
		}
		int i2 = v2.size();
		for (int i = 0; i < v2.size(); i++) {
			i2 += to_string(v2[i]).size();
		}
		return i1 > i2;
	});
	for (int i = 0; i < testList.size(); i++) {
		if (i > 0) ret += ", ";
		ret += "(";
		for (int j = 0; j < testList[i].size(); j++) {
			if (j > 0) ret += ", ";
			ret += to_string(testList[i][j]);
		}
		ret += ")";
	}
	ret += "]";
	return ret;
}
<|endoftext|>