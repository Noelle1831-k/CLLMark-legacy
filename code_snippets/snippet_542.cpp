	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (65 <= c && c <= 90) ret += (char)(c + 32);
		else ret += c;
	}
	return ret;
}
int countUpper(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (65 <= c && c <= 90) count++;
	}
	return count;
}
int countWhiteSpaces(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == ' ') count++;
	}
	return count;
}
int countSymbols(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '~' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '_' || c == '=') count++;
	}
	return count;
}
int countVowels(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') count++;
	}
	return count;
}
int countLines(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '\n') count++;
	}
	return count + 1;
}
string reverse(string str) {
	string ret = "";
	for (int i = str.size() - 1; i >= 0; i--) {
		ret += str[i];
	}
	return ret;
}
string toCamelCase(string str) {
	string ret = "";
	str[0] = tolower(str[0]);
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == ' ') {
			str[i + 1] = toupper(str[i + 1]);
		}
	}
	return str;
}
string toDotCase(string str) {
	string ret = "";
	str[0] = tolower(str[0]);
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == ' ') {
			ret += '.';
		} else {
			ret += c;
		}
	}
	return ret;
}
string toDashCase(string str) {
	string ret = "";
	str[0] = tolower(str[0]);
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == ' ') {
			ret += '-';
		} else {
			ret += c;
		}
	}
	return ret;
}
string toTitleCase(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (i == 0) ret += toupper(c);
		else {
			if (c == ' ') {
				str[i + 1] = toupper(str[i + 1]);
			}
		}
	}
	return ret;
}
string toLowerCase(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		ret += tolower(c);
	}
	return ret;
}
string toUpperCase(string str) {
	string ret = "";
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		ret += toupper(c);
	}
	return ret;
}
/**
 * Write a c++ function to count the number of lines in the given string.
 * > countLines(string("person"))
 * 1
