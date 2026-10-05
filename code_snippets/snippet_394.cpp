	vector<string> res;
	for (int i = 0; i < str.size(); i++) {
		string tmp = str[i];
		if (tmp.length() <= l) {
			res.push_back(tmp);
		}
	}
	return res;
}
int countSpecifiedWords(vector<string> str, vector<string> words) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		string tmp = str[i];
		for (int j = 0; j < words.size(); j++) {
			string tmp2 = words[j];
			if (tmp == tmp2) {
				count++;
			}
		}
	}
	return count;
}
int countSpecifiedWordsRemove(vector<string> &str, vector<string> words) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		string tmp = str[i];
		for (int j = 0; j < words.size(); j++) {
			string tmp2 = words[j];
			if (tmp == tmp2) {
				str.erase(str.begin() + i);
				count++;
				i--;
				break;
			}
		}
	}
	return count;
}
int countSpecifiedWordsRemove2(vector<string> &str, vector<string> words) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		string tmp = str[i];
		for (int j = 0; j < words.size(); j++) {
			string tmp2 = words[j];
			if (tmp == tmp2) {
				str.erase(str.begin() + i);
				count++;
				i--;
				break;
			}
		}
	}
	return count;
}
int countSpecifiedWordsRemove3(vector<string> &str, vector<string> words) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		string tmp = str[i];
		for (int j = 0; j < words.size(); j++) {
			string tmp2 = words[j];
			if (tmp == tmp2) {
				str.erase(str.begin() + i);
				count++;
				i--;
				break;
			}
		}
	}
	return count;
}
int countSpecifiedWordsRemove4(vector<string> &str, vector<string> words) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		string tmp = str[i];
		for (int j = 0; j < words.size(); j++) {
			string tmp2 = words[j];
			if (tmp == tmp2) {
				str.erase(str.begin() + i);
				count++;
				i--;
				break;
			}
		}
	}
	return count;
}
/**
 * Write a function to count specified words from a give list of string values and remove those words from original list (use move).
 * > countSpecifiedWordsRemove5(vector<string>{string("cat"), string("cat"), string("cat")}, vector<string>{string("cat")})
 * 3
 * > countSpecifiedWordsRemove5(vector<string>{string("cat"), string("cat"), string("cat")}, vector<string>{string("cat"), string("cat")})
 * 1
 * > countSpecifiedWordsRemove5(vector<string>{string("cat"), string("cat"), string("cat")}, vector<string>{string("cat"), string("cat"), string("cat")})
 * 0
 * > countSpecifiedWordsRemove5(vector<string>{string("