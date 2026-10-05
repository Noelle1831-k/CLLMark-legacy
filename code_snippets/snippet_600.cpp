	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == x[0]) {
			count++;
			while (i < str.length() && str[i] == x[0])
				i++;
		}
	}
	return count;
}
int main() {
	string str, x;
	cin >> str >> x;
	cout << countChar(str, x);
	return 0;
}
<|endoftext|>