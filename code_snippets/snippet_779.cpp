	string ret = "";
	for(int i = 0; i < text.size(); i++) {
		if(text[i] != ' ') {
			ret += text[i];
		}
	}
	return ret;
}
int main() {
	string text = "   hello world";
	string text2 = "   hello world      ";
	string text3 = "   hello world      python  language";
	string text4 = "   hello world      python  language";
	string text5 = "   hello world      python  language";
	string ret = removeSpaces(text);
	string ret2 = removeSpaces(text2);
	string ret3 = removeSpaces(text3);
	string ret4 = removeSpaces(text4);
	string ret5 = removeSpaces(text5);
	cout << ret << endl;
	cout << ret2 << endl;
	cout << ret3 << endl;
	cout << ret4 << endl;
	cout << ret5 << endl;
	return 0;
}
<|endoftext|>