	map<char, int> mymap;
	string ret = "";
	for (int i = 0; i < str1.length(); i++) {
		mymap[str1[i]]++;
	}
	map<char, int>::iterator itr;
	itr = mymap.begin();
	while (itr != mymap.end()) {
		if (itr->second > mymap[ret]) {
			ret = itr->first;
		}
		itr++;
	}
	return ret;
}
<|endoftext|>