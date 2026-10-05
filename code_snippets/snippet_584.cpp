	string out = "";
	string::iterator iter1, iter2;
	iter1 = str.begin();
	while (iter1 != str.end()) {
		iter2 = iter1;
		while (iter2 != str.end() && *iter2 == *chr) iter2++;
		if (iter2 != iter1) {
			out += iter1;
			out += iter2;
			iter1 = iter2;
		}
	}
	return out;
}
int main() {
	string str, chr;
	while (1) {
		cout << "Enter a string : ";
		cin >> str;
		cout << "Enter a character: ";
		cin >> chr;
		cout << "Output: " << replace(str, chr) << endl;
	}
	return 0;
}
<|endoftext|>