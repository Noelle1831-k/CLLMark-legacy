	map<char, int> charCount;
	string firstRepeatedChar = "\0";
	for (int i = 0; i < str.size(); i++) {
		char character = str[i];
		charCount[character]++;
		if (charCount[character] > 1) {
			firstRepeatedChar = character;
			break;
		}
	}
	return firstRepeatedChar;
}
int main() {
	string str("Google");
	string firstRepeatedChar = firstRepeatedChar(str);
	cout << firstRepeatedChar;
	return 0;
}
<|endoftext|>