	string s1, s2;
	s1 = to_string(n1);
	s2 = to_string(n2);
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		count += abs(s1[i] - s2[i]);
	}
	return count;
}
<|endoftext|>