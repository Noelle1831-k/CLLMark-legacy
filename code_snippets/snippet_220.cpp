	string sub_str;
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		sub_str += str[i];
		count++;
		count += countSubstr(sub_str);
	}
	return count;
}
int countSubstr(string sub_str) {
	int count = 0;
	while (sub_str.length() != 0) {
		sub_str.erase(0, 1);
		count++;
	}
	return count;
}
int main() {
	string str("abc");
	cout << numberOfSubstrings(str) << endl;
	str = "abcd";
	cout << numberOfSubstrings(str) << endl;
	str = "abcde";
	cout << numberOfSubstrings(str) << endl;
	return 0;
}
<|endoftext|>