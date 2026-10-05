	vector<int> ludics;
	ludics.push_back(1);
	ludics.push_back(2);
	ludics.push_back(3);
	ludics.push_back(5);
	ludics.push_back(7);
	while(ludics.back() <= n) {
		ludics.push_back( ludics.back() - 1 );
		ludics.push_back( ludics.back() + 1 );
	}
	ludics.pop_back();
	return ludics;
}
bool allInOrder(string str1, string str2, int start = 0) {
	if(str1.size() == 0 && str2.size() == 0)
		return true;
	if(str1.size() == 0 || str2.size() == 0)
		return false;
	char s1 = str1[0];
	char s2 = str2[start];
	str1.erase(str1.begin());
	str2.erase(str2.begin() + start);
	if(s1 == s2)
		return allInOrder(str1, str2, 0);
	else
		return allInOrder(str1, str2, start + 1);
}
bool allInOrder2(string str1, string str2, int start = 0) {
	while(str1.size() != 0 && str2.size() != 0) {
		char s1 = str1[0];
		char s2 = str2[start];
		str1.erase(str1.begin());
		str2.erase(str2.begin() + start);
		if(s1 == s2)
			continue;
		else
			return false;
	}
	return true;
}
bool allInOrder3(string str1, string str2, int start = 0) {
	while(str1.size() != 0 && str2.size() != 0) {
		char s1 = str1[0];
		char s2 = str2[start];
		str1.erase(str1.begin());
		str2.erase(str2.begin() + start);
		if(s1 == s2)
			continue;
		else
			return false;
	}
	return true;
}
bool allInOrder4(string str1, string str2, int start = 0) {
	while(str1.size() != 0 && str2.size() != 0) {
		char s1 = str1[0];
		char s2 = str2[start];
		str1.erase(str1.begin());
		str2.erase(str2.begin() + start);
		if(s1 == s2)
			continue;
		else
			return false;
	}
	return true;
}
bool allInOrder5(string str1, string str2, int start = 0) {
	while(str1.size() != 0 && str2.size() != 0) {
		char s1 = str1[0];
		char s2 = str2[start];
		str1.erase(str1.begin());
		str2.erase(str2.begin() + start);
		if(s1 == s2)
			continue;
		else
			return false;
	}
	return true;
}
bool allInOrder6(string str1, string str2, int start = 0) {
	while(str1.size() != 0 && str2.size() != 0) {
		char s1 = str1[0];
		char s2 = str2[start];
		str1.erase(str1.begin());
		str2.erase(str2.begin() + start);
		if(s1 == s2)
			continue;
		else
			return false;
	}
	return true;
}
/**
 * Return True if all the characters of the given string
 * appear in the given order in string2.
 *
 * > allInOrder7("ba", "ab")
 * True
 * > allInOrder7("aab", "acb")
 * False
 * > allInOrder7("aab", "aac")
 *