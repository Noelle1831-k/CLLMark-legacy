	string out_str;
	char char_to_swap;
	string original_str = str;
	vector<string> permute_str;
	while(str.size()>0){
		char_to_swap = str[0];
		str.erase(0,1);
		for(int i = 0; i<str.size();i++){
			char_to_swap = str[i];
			str[i] = str[0];
			str[0] = char_to_swap;
			out_str = str;
			permute_str.push_back(out_str);
		}
	}
	return permute_str;
}
<|endoftext|>