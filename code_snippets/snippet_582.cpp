	int count = 0;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == chr[0]) {
			count++;
		}
	}
	return count;
}
int main() {
	string str, chr;
	std::cin >> str >> chr;
	std::cout << countChar(str, chr) << std::endl;
	return 0;
}
<|endoftext|>