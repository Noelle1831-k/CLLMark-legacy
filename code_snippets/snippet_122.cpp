	string ret = "";
	string::iterator iter1, iter2;
	iter1 = str1.begin();
	iter2 = str1.end();
	while (iter1 != iter2) {
		char c = *iter1;
		char c_lower = tolower(c);
		char c_upper = toupper(c);
		if (c_lower == 'a' || c_lower == 'e' || c_lower == 'i' || c_lower == 'o' || c_lower == 'u' || c_upper == 'A' || c_upper == 'E' || c_upper == 'I' || c_upper == 'O' || c_upper == 'U') {
			ret.insert(0, c);
		}
		iter1++;
	}
	string::iterator iter1, iter2;
	iter1 = str1.begin();
	iter2 = str1.end();
	while (iter1 != iter2) {
		char c = *iter1;
		char c_lower = tolower(c);
		char c_upper = toupper(c);
		if (c_lower == 'a' || c_lower == 'e' || c_lower == 'i' || c_lower == 'o' || c_lower == 'u' || c_upper == 'A' || c_upper == 'E' || c_upper == 'I' || c_upper == 'O' || c_upper == 'U') {
			str1.erase(iter1);
		}
		else {
			iter1++;
		}
	}
	str1.append(ret);
	return str1;
}
int main() {
	string ret = reverseVowels("aBcde");
	cout << ret << endl;
	return 0;
}
<|endoftext|>