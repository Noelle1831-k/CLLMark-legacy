	string ret = "";
	for (int i = 0; i < str.length(); i++) {
		char s = str[i];
		if (s >= 'A' && s <= 'Z') {
			s = s - 'A' + 'a';
		}
		ret.push_back(s);
	}
	return ret;
}
<|endoftext|>