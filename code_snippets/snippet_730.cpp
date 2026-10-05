	string tmp(s1); 
	int count = 0; 
	for (int i = 0; i < s1.size(); i++) {
		while (s1[i] != s2[i]) {
			s1.erase(i, 1); 
			s1.insert(i, string(1, tmp[i])); 
			count++; 
		}
	}
	return count;
}
int main() {
	string s1, s2;
	std::cin >> s1 >> s2;
	std::cout << minSwaps(s1, s2) << std::endl;
	return 0;
}
<|endoftext|>