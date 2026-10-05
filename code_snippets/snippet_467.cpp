	vector<int> res;
	int i = 0;
	while(i<=text.size()-pattern.size()){
		j = 0;
		while(j<pattern.size()){
			if(text[i+j] != pattern[j])
				break;
			j++;
		}
		if(j==pattern.size()){
			res.push_back(i);
			res.push_back(i+j-1);
		}
		i++;
	}
	return res;
}
<|endoftext|>