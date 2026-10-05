	string ret = "";
	for (int i = 0; i < str1.size(); i++) {
		char s = str1[i];
		if (i == 0) ret += toupper(s);
		else if (i == str1.size() - 1) ret += toupper(s);
		else ret += s;
	}
	return ret;
}
int main() {
	string str1;
	while (1) {
		cout << "Enter a string : ";
		cin >> str1;
		string ret = capitalizeFirstLastLetters(str1);
		cout << "Result : " << ret << endl;
	}
	return 0;
}
<|endoftext|>