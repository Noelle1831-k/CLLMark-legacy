	string s = to_string(num);
	string reverse_s = reverse(s.begin(), s.end());
	string palindrome;
	string reverse_palindrome;
	if (reverse_s.compare(s) > 0)
		palindrome = reverse_s;
	else {
		while (reverse_s.compare(s) < 0) {
			s.push_back('0');
			reverse_s.push_back('0');
		}
		palindrome = reverse_s;
	}
	reverse_palindrome = reverse(palindrome.begin(), palindrome.end());
	return stoi(palindrome) - stoi(reverse_palindrome);
}
int main() {
	int num = 8888;
	cout << previousPalindrome(num);
	return 0;
}
<|endoftext|>