	str = str.replace(" ", "\n");
	string *s = new string(str);
	vector<string> res;
	while(s[0] != "") {
		string tmp = "";
		while(s[0] != "" && s[0] != "\n") {
			tmp += s[0];
			s[0] = s[0].next;
		}
		s[0] = s[0].next;
		res.push_back(tmp);
	}
	return res;
}
<|endoftext|>