	vector<int> res;
	for(auto it = list.begin(); it != list.end(); it++){
		if(*it % 2 != 0)
		res.push_back(*it);
	}
	return res;
}
<|endoftext|>