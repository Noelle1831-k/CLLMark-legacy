	string out;
	for (char &i : str)
		out += (i == ' ') ? "%20" : i;
	return out;
}
int main() {
	string text;
	cout << "Enter a text: ";
	getline(cin, text);
	cout << replaceSpaces(text) << endl;
	return 0;
}
<|endoftext|>