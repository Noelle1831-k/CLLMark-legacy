	string ret = "";
	for (int i = 0; i < testList.size(); i++) {
		string tmp = "";
		for (int j = 0; j < testList[i].size(); j++) {
			string tmp2 = "";
			for (int k = 0; k < testList[i][j].size(); k++) {
				tmp2 += to_string(testList[i][j][k]) + ", ";
			}
			tmp += "{" + tmp2.substr(0, tmp2.size() - 2) + "}, ";
		}
		ret += "{" + tmp.substr(0, tmp.size() - 2) + "}, ";
	}
	return ret.substr(0, ret.size() - 2);
}
<|endoftext|>