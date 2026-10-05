	map<string, string> cache;
	string ret = "0";
	for (unsigned i = 0; i < testList.size(); i++) {
		string reverse = testList[i];
		reverse(reverse.begin(), reverse.end());
		string cachedValue = findInCache(reverse, cache);
		if (cachedValue != "") {
			ret = findInCache(reverse, cache);
			cache.clear();
			cache[testList[i]] = ret;
			break;
		}
		cache[testList[i]] = findInCache(reverse, cache);
		cache.clear();
	}
	return ret;
}
string findInCache(string reverse, map<string, string> cache) {
	string ret = "0";
	map<string, string>::iterator iter = cache.find(reverse);
	if (iter != cache.end()) {
		ret = iter->second;
	}
	return ret;
}
int main(int argc, const char * argv[]) {
	string ret = countReversePairs(vector<string>{string("julia"), string("best"), string("tseb"), string("for"), string("ailuj")});
	cout << ret << endl;
	return 0;
}
<|endoftext|>