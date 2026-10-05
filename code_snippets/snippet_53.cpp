	string s = to_string(n);
	string reverse_s = s;
	reverse(reverse_s.begin(), reverse_s.end());
	string double_reverse_s = reverse_s;
	reverse(double_reverse_s.begin(), double_reverse_s.end());
	return stoi(reverse_s) + 1 == stoi(double_reverse_s);
}
int main() {
	cout << check(70) << endl;
	cout << check(23) << endl;
	cout << check(73) << endl;
	return 0;
}
<|endoftext|>