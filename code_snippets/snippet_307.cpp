	int count_d = 0, count_l = 0;
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			count_l++;
		} else if (isdigit(s[i])) {
			count_d++;
		}
	}
	return {count_d, count_l};
}
int main() {
	string s;
	while (1) {
		s = "";
		cout << "Enter a string, or enter 'x' to stop.\n";
		cin >> s;
		if (s == "x") {
			break;
		}
		vector<int> res = digLet(s);
		cout << "The number of digits is " << res[0] << ".\n";
		cout << "The number of letters is " << res[1] << ".\n";
	}
}
<|endoftext|>