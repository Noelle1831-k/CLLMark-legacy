	string reverse_s = "";
	string tmp = "";
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != ' ') {
			tmp += s[i];
		} else {
			reverse_s += " " + tmp;
			tmp = "";
		}
	}
	reverse_s += " " + tmp;
	reverse(reverse_s.begin(), reverse_s.end());
	return reverse_s;
}
int main()
{
	string s = "reverse python program";
	s = reverseWords(s);
	cout << s << endl;
	return 0;
}
<|endoftext|>