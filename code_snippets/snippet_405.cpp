	for (const auto &value : dict) {
		if (value.second != n) {
			return false;
		}
	}
	return true;
}
string longestWord(string first, string second, string third, string fourth) {
	string ret = "";
	string ret_2 = "";
	string ret_3 = "";
	string ret_4 = "";
	string *words[4] = {&first, &second, &third, &fourth};
	string *words_2[4] = {&ret, &ret_2, &ret_3, &ret_4};
	for (int i = 0; i < 4; i++) {
		if (words[i]->length() > words_2[i]->length()) {
			*words_2[i] = *words[i];
		}
	}
	return *words_2[0];
}
string *longestWordPointers(string *first, string *second, string *third, string *fourth) {
	string *ret = new string("");
	string *ret_2 = new string("");
	string *ret_3 = new string("");
	string *ret_4 = new string("");
	string *words[4] = {first, second, third, fourth};
	string *words_2[4] = {ret, ret_2, ret_3, ret_4};
	for (int i = 0; i < 4; i++) {
		if (words[i]->length() > words_2[i]->length()) {
			*words_2[i] = *words[i];
		}
	}
	return *words_2[0];
}
const string *longestWordPointersConst(const string *first, const string *second, const string *third, const string *fourth) {
	string *ret = new string("");
	string *ret_2 = new string("");
	string *ret_3 = new string("");
	string *ret_4 = new string("");
	const string *words[4] = {first, second, third, fourth};
	string *words_2[4] = {ret, ret_2, ret_3, ret_4};
	for (int i = 0; i < 4; i++) {
		if (words[i]->length() > words_2[i]->length()) {
			*words_2[i] = *words[i];
		}
	}
	return *words_2[0];
}
string *longestWordPointersConstCast(string *first, string *second, string *third, string *fourth) {
	string *ret = new string("");
	string *ret_2 = new string("");
	string *ret_3 = new string("");
	string *ret_4 = new string("");
	const string *words[4] = {first, second, third, fourth};
	string *words_2[4] = {ret, ret_2, ret_3, ret_4};
	for (int i = 0; i < 4; i++) {
		if (words[i]->length() > words_2[i]->length()) {
			*words_2[i] = *words[i];
		}
	}
	return *words_2[0];
}
string *longestWordPointersConstCastConstCast(string *first, string *second, string *third, string *fourth) {
	string *ret = new string("");
	string *ret_2 = new string("");
	string *ret_3 = new string("");
	string *ret_4 = new string("");
	const string *words[4] = {first, second, third, fourth};
	string *words_2[4] = {ret, ret_2, ret_3, ret_4};
	for (int i = 0; i < 4; i++) {
		if (words[i]->length() > words_2[i]->length()) {
			*words_2[i] = *words[i];
		}
	}
	return *words_2[0];
}
string *longestWordPointersConstCastConstCastConstCast(string *first, string *second, string *third, string *fourth) {
	string *ret = new string("");
	string *ret_2 = new string("");
	string *ret_3 = new string("");
	string *ret_4 = new string("");
	const string *words[4] = {first, second, third, fourth};
	string *words_2[4] = {ret, ret_2, ret_3, ret_4};
	for (int i = 0; i < 4; i++) {
		if (words[i]->length() > words_2[i]->length()) {
			*words_2[i] = *words[i];
		}
