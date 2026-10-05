	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < vowels.length(); j++) {
			if (str[i] == vowels[j]) {
				count++;
			}
		}
	}
	return count;
}
int main() {
	string str, vowels;
	std::cin >> str >> vowels;
	std::cout << checkVow(str, vowels);
	return 0;
}
<|endoftext|>