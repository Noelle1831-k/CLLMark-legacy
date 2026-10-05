	map<char,int> mp;
	string ret = "";
	for(auto ch : s){
		mp[ch]++;
	}
	while(mp.size()>0){
		char max = '-';
		int count = 0;
		for(auto it:mp){
			if(it.second>count){
				max = it.first;
				count = it.second;
			}
		}
		mp.erase(max);
		ret.push_back(max);
		mp[max]--;
	}
	return ret;
}
<|endoftext|>