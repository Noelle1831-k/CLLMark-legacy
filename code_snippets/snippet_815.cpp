	string text2;
	for (int i = 0; i < text.length(); i++) {
		char c = text[i];
		if (i > 0 && (isupper(c) ^ isupper(text[i - 1]))) text2 += '_';
		text2 += tolower(c);
	}
	return text2;
}
int main() {
	string text, text2;
	while (1) {
		cout << "Enter a camel case string: ";
		getline(cin, text);
		if (text == "") break;
		text2 = camelToSnake(text);
		cout << "Result: " << text2 << endl;
	}
	return 0;
}
<|endoftext|>