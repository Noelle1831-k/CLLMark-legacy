	vector<vector<string>> list2;
	string buffer = "";
	for (unsigned int i = 0; i < list1.size(); i++) {
		string element = list1[i];
		for (unsigned int j = 0; j < element.length(); j++) {
			string cur = element[j];
			if (cur == ' ') {
				list2.push_back(string(buffer));
				buffer = "";
			} else {
				buffer += cur;
			}
		}
		if (buffer.length() > 0) {
			list2.push_back(string(buffer));
			buffer = "";
		}
	}
	return list2;
}
<|endoftext|>