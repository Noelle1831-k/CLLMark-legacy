	vector<int> res={0,0,0};
	for(auto ch:str){
		if (ch.isalpha()) res[0]++;
		else if (ch.isalnum()) res[1]++;
		else res[2]++;
	}
	return res;
}
<|endoftext|>