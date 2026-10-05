	int count = 0;
	string target = "std";
	int targetLength = target.length();
	string::size_type lastPos = s.find(target);
	while (lastPos != string::npos) {
		count++;
		lastPos = s.find(target, lastPos + targetLength);
	}
	return count;
}
int count_unique_chars_1(string s) {
	int count = 0;
	string::iterator itr;
	for (itr = s.begin(); itr != s.end(); ++itr) {
		count += (1 << (int (*itr) - 97)) & 1;
	}
	return count;
}
int count_unique_chars_2(string s) {
	int count = 0;
	string::iterator itr;
	string::iterator itr2;
	for (itr = s.begin(); itr != s.end(); ++itr) {
		itr2 = find(s.begin(), itr, *itr);
		count += (itr2 == itr) ? 1 : 0;
	}
	return count;
}
int count_unique_chars_3(string s) {
	int count = 0;
	string::iterator itr;
	string::iterator itr2;
	string::iterator itr3;
	string::iterator itr4;
	for (itr = s.begin(); itr != s.end(); ++itr) {
		itr2 = find(s.begin(), itr, *itr);
		itr3 = find(itr2 + 1, itr, *itr);
		itr4 = find(itr3 + 1, itr, *itr);
		count += (itr2 == itr3 && itr3 == itr4) ? 1 : 0;
	}
	return count;
}
int count_unique_chars_4(string s) {
	int count = 0;
	string::iterator itr;
	string::iterator itr2;
	string::iterator itr3;
	string::iterator itr4;
	string::iterator itr5;
	for (itr = s.begin(); itr != s.end(); ++itr) {
		itr2 = find(s.begin(), itr, *itr);
		itr3 = find(itr2 + 1, itr, *itr);
		itr4 = find(itr3 + 1, itr, *itr);
		itr5 = find(itr4 + 1, itr, *itr);
		count += (itr2 == itr3 && itr3 == itr4 && itr4 == itr5) ? 1 : 0;
	}
	return count;
}
int count_unique_chars_5(string s) {
	int count = 0;
	string::iterator itr;
	string::iterator itr2;
	string::iterator itr3;
	string::iterator itr4;
	string::iterator itr5;
	string::iterator itr6;
	for (itr = s.begin(); itr != s.end(); ++itr) {
		itr2 = find(s.begin(), itr, *itr);
		itr3 = find(itr2 + 1, itr, *itr);
		itr4 = find(itr3 + 1, itr, *itr);
		itr5 = find(itr4 + 1, itr, *itr);
		itr6 = find(itr5 + 1, itr, *itr);
		count += (itr2 == itr3 && itr3 == itr4 && itr4 == itr5 && itr5 == itr6) ? 1 : 0;
	}
	return count;
}
int count_unique_chars_6(string s) {
	int count = 0;
	string::iterator itr;
	string::iterator itr2;
	string::iterator itr3;
	string::iterator itr4;
	string::iterator itr5;
	string::iterator itr6;
	string::iterator itr7;
	for (itr = s.begin(); itr != s.end(); ++itr) {
		itr2 = find(s.begin(), itr, *itr);
		itr3 = find(itr2 + 1, itr, *itr);
		itr4 = find(itr3 + 1, itr, *itr);
		itr5 = find(itr4 + 1, itr, *itr);
		itr6 = find(itr5 + 1, itr, *itr);
		itr7 = find(itr6 + 1, itr, *itr);
		count += (itr2 == itr3 && itr3 == itr4 && itr4 == itr5 && itr5 == itr6 && itr6 == itr7) ? 1 : 0;
	}
	return count;
}
int count_unique_chars_7(string s) {
	int count = 0;
	string::iterator itr;
	string::iterator itr2;
	string::iterator itr3;
	string::iterator itr4;
	string::iterator itr5;
	string::iterator itr6;
	string::iterator itr7;
	string::iterator itr8;
	for (itr = s.begin(); itr != s.end(); ++itr) {
		itr2 = find(s.begin(), itr, *itr);
		itr3 = find(itr2 + 1, itr, *itr);
		itr4 = find(itr3 + 1, itr, *itr);
		itr5 = find(itr4 + 1, itr, *itr);
		itr6 = find(itr5 + 1, itr, *itr);
		itr7 = find(itr6 + 1, itr, *itr);
		itr8 = find(itr7 + 1, itr, *itr);
		count += (itr2 == itr3 && itr3 == itr4 && itr4 == itr5 && itr5 == itr6 && itr6 == itr7 && itr7 == itr8) ? 1 : 0;
	}
	return count;
