	string ret = "[";
	for (int i = 0; i < testList.size(); i++) {
		string tmp = "(" + testList[i][0] + ", " + testList[i][1] + ")";
		ret += tmp;
		if (i < testList.size() - 1) ret += ", ";
	}
	ret += "]";
	return ret;
}
<|endoftext|>