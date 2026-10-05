	string str = "";
	for(int i = 0; i < str1.length(); i++) {
		if(str1[i] == ' ') {
			str += chr;
		} else {
			str += str1[i];
		}
	}
	return str;
}
int main() {
	string str, chr;
	cin >> str >> chr;
	cout << replaceBlank(str, chr);
	return 0;
}
<|endoftext|>