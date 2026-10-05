	string out = "";
	string::iterator itr;
	for (itr = s.begin(); itr != s.end(); itr++) {
		if (ispunct(*itr) == 0 && isalpha(*itr) == 0) {
			out += *itr;
		}
	}
	return out;
}
int main() {
	string s = "123abcjw:, .@! eiw";
	string out = removeChar(s);
	cout << out << endl;
}
<|endoftext|>