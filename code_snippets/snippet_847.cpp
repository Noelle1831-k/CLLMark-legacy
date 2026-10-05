	string ret = "";
	while (d--) {
		char c = s[0];
		s.erase(s.begin());
		s.push_back(c);
		ret.push_back(c);
	}
	s.append(ret);
	return s;
}
int main() {
	string s = "bigdata";
	int d = 3;
	cout << leftRotate(s, d) << endl;
	return 0;
}
<|endoftext|>