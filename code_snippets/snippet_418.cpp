	map<char, int> mymap; 
	map<char, int>::iterator itr; 
	string ret = "";
	for (int i = 0; i < str1.size(); i++) {
		mymap[str1[i]]++;
		itr = mymap.begin();
	}
	while (itr != mymap.end()) {
		if (itr->second > ret.size())
			ret = itr->first;
		itr++;
	}
	return ret;
}
int main() {
	string str1;
	while (1) {
		str1 = getStringInput();
		if (str1 == "")
			break;
		printString(getMaxOccuringChar(str1));
	}
	return 0;
}
<|endoftext|>