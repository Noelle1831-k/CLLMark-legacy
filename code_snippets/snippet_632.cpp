	vector<string> res;
	string text2;
	while(regex_search(text1,smatch,regex(R"(\"[^\"]*?\")"))){
		text2 = smatch[0];
		text2 = text2.substr(1,text2.size()-2);
		res.push_back(text2);
		text1 = smatch.suffix();
	}
	return res;
}
<|endoftext|>