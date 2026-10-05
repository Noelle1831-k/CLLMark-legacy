	string ret = "";
	while(testStr.size() > 0) {
		string::size_type sz = testStr.find(' ');
		if(sz == string::npos || sz == 0) sz = testStr.size();
		if(sz != k) ret += testStr.substr(0, sz);
		testStr.erase(0, sz + 1);
	}
	return ret;
}
int main() {
	string testStr;
	while(getline(cin, testStr)) {
		string ret = removeLength(testStr, atoi(testStr.substr(0, testStr.find(' ')).c_str()));
		cout << ret << endl;
	}
	return 0;
}
<|endoftext|>