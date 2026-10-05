	string1 += string1;
	return string1.find(string2) != string::npos;
}
int main() {
	string string1, string2;
	while (1) {
		cin >> string1 >> string2;
		cout << (areRotations(string1, string2) ? "true" : "false") << endl;
	}
	return 0;
}
<|endoftext|>