	string w;
	vector<string> words;
	while(str!=""):
		w="";
		while(str[0]!=' '):
			w+=str[0];
			str=str.substr(1);
		str=str.substr(1);
		if(w.length()>n):
			words.push_back(w);
	return words;
}
<|endoftext|>