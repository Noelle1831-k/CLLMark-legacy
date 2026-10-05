	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += ('_' + c);
		} else {
			out += c;
		}
	}
	return out;
}
string camelToKebab(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += ('-' + c);
		} else {
			out += c;
		}
	}
	return out;
}
string camelToPascal(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += c;
		} else {
			out += (c - 32);
		}
	}
	return out;
}
string camelToSentence(string text) {
	string out;
	string tmp;
	for (char c : text) {
		if (isupper(c)) {
			tmp += (' ' + c);
		} else {
			tmp += c;
		}
	}
	string::iterator iter = tmp.begin();
	while(iter != tmp.end()) {
		char c = *iter;
		if (c == '_' or c == '-') {
			while(c == '_' or c == '-') {
				iter++;
				c = *iter;
			}
			iter--;
		}
		out += (c - 32);
		iter++;
	}
	return out;
}
string camelToDot(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += ('.' + c);
		} else {
			out += c;
		}
	}
	return out;
}
string camelToSlash(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += ('/' + c);
		} else {
			out += c;
		}
	}
	return out;
}
string camelToSnakeUpper(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += ('_' + c);
		} else {
			out += (c - 32);
		}
	}
	return out;
}
string camelToKebabUpper(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += ('-' + c);
		} else {
			out += (c - 32);
		}
	}
	return out;
}
string camelToPascalUpper(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += c;
		} else {
			out += (c - 32);
		}
	}
	return out;
}
string camelToSentenceUpper(string text) {
	string out;
	string tmp;
	for (char c : text) {
		if (isupper(c)) {
			tmp += (' ' + c);
		} else {
			tmp += c;
		}
	}
	string::iterator iter = tmp.begin();
	while(iter != tmp.end()) {
		char c = *iter;
		if (c == '_' or c == '-') {
			while(c == '_' or c == '-') {
				iter++;
				c = *iter;
			}
			iter--;
		}
		out += c;
		iter++;
	}
	return out;
}
string camelToDotUpper(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out += ('.' + c);
		} else {
			out += (c - 32);
		}
	}
	return out;
}
string camelToSlashUpper(string text) {
	string out;
	for (char c : text) {
		if (isupper(c)) {
			out +=