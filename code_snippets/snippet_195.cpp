	string regex("[a-zA-Z0-9]*");
	string::const_iterator iter = str.begin();
	while (regex_match(iter, str.end(), regex)) {
		return true;
	}
	return false;
}
int main() {
	string str("a1B");
	string::const_iterator iter = str.begin();
	while (regex_match(iter, str.end(), regex("[a-zA-Z0-9]*"))) {
		cout << *iter;
		iter++;
	}
	cout << endl;
	return 0;
}
<|endoftext|>