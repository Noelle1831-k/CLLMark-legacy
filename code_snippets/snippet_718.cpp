	l.erase(remove_if(l.begin(), l.end(), [=](int i){return i % 2 == 0;}), l.end());
	return l;
}
string addPrefix(string s) {
	string prefix = "";
	while (s.length() < 8)
		s = "0" + s;
	return s;
}
int printSum(vector<int> l) {
	int result = 0;
	for (int i = 0; i < l.size(); i++) {
		result += l[i];
	}
	return result;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
string printReverse(string s) {
	string reverse = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		reverse += s[i];
	}
	return reverse;
}
/**
 * Write a c++ function to print the sum of the given array of integer numbers.
 * > printSum([1, 2, 3, 4])
 * 10
 * > printSum([1, 2, 3, 4, 5])
 * 15
 * > printSum([])
 * 