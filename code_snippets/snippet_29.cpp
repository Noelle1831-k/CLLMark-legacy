	char prev = s[0];
	int count = 1;
	for (int i = 1; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringWithEqualBegins(string s) {
	char prev = s[0];
	int count = 1;
	for (int i = 1; i < s.size(); i++) {
		if (prev != s[i]) {
			count++;
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
int countSubstringEndsWith(string s, string e) {
	char prev = e[0];
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (prev == s[i]) {
			count++;
			if (i >= s.size() - e.size()) {
				count = 0;
			}
		}
		else {
			prev = s[i];
			count = 1;
		}
	}
	return count;
}
/**