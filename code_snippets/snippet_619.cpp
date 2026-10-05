	string tmp="";
	vector<string> res;
	for (int i=0;i<str.length();i++) {
		if (str[i]==32) {
			res.push_back(tmp);
			tmp="";
		}
		else {
			tmp+=str[i];
		}
	}
	res.push_back(tmp);
	return res;
}
<|endoftext|>