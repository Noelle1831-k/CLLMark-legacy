	string ret = "";
	for(int i=0; i<text.size(); i++) {
		if(text[i] == ' ') {
			ret.push_back('_');
		} else {
			ret.push_back(text[i]);
		}
	}
	return ret;
}
int main() {
	string text;
	while(getline(cin, text)) {
		cout << replaceSpaces(text) << endl;
	}
	return 0;
}
<|endoftext|>