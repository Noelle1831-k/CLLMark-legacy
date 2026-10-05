	string ret = "[";
	for (unsigned i = 0; i < testList.size(); i++) {
		string tmp = "(";
		for (unsigned j = 0; j < testList[i].size(); j++) {
			if (j != 0) tmp += ", ";
			tmp += to_string(testList[i][j]);
		}
		while (tmp.back() == '0') tmp.pop_back();
		while (tmp.back() == ',') tmp.pop_back();
		if (i != 0) ret += ", ";
		ret += tmp + ")";
	}
	ret += "]";
	return ret;
}
<|endoftext|>