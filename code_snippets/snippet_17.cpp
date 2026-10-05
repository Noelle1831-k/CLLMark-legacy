	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		if (find(secondString.begin(), secondString.end(), str[i]) == secondString.end()) {
			ret += str[i];
		}
	}
	return ret;
}
int main() {
	string str, secondString;
	cin >> str >> secondString;
	cout << removeDirtyChars(str, secondString) << endl;
	return 0;
}
<|endoftext|>