	while (x != 0) {
		if (x % 2 != 0) {
			return false;
		}
		x = x / 2;
	}
	return true;
}
bool checkPalindrome(string s) {
	string reverse_s = s;
	reverse(reverse_s.begin(), reverse_s.end());
	return (reverse_s == s);
}
int count2(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count3(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count4(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count5(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count6(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count7(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count8(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count9(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count10(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count11(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
int count12(string s, string x) {
	int count = 0;
	string::size_type last = s.find(x);
	while (last != string::npos) {
		count++;
		last = s.find(x, last + 1);
	}
	return count;
}
/**
 * Write a c++ function to count the number of times a substring (of length 13) appears in a given string.
 * > count13("aabcdcbaa", "cb")
