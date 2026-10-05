	string out_str;
	regex rgx("[a-z]{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeUppercase(string str1) {
	string out_str;
	regex rgx("[A-Z]{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeSpecialCharacters(string str1) {
	string out_str;
	regex rgx("[^a-zA-Z]{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeWhitespace(string str1) {
	string out_str;
	regex rgx("\s{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeNonASCII(string str1) {
	string out_str;
	regex rgx("\x80{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeExtraSpace(string str1) {
	string out_str;
	regex rgx("\s{2,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeExtraSpaceChar(string str1) {
	string out_str;
	regex rgx("\s{1,}\S{1,}\s{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeExtraSpaceCharStartEnd(string str1) {
	string out_str;
	regex rgx("\s{1,}\S{1,}\s{1,}\S{1,}\s{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeExtraSpaceCharStartEnd(string str1) {
	string out_str;
	regex rgx("\s{1,}\S{1,}\s{1,}\S{1,}\s{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeExtraSpaceCharStartEnd(string str1) {
	string out_str;
	regex rgx("\s{1,}\S{1,}\s{1,}\S{1,}\s{1,}");
	sregex_iterator iter(str1.begin(), str1.end(), rgx);
	sregex_iterator iter_end;
	while (iter != iter_end) {
		smatch m = *iter;
		string sub_str = m.str();
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		sub_str = sub_str.substr(1, sub_str.length() - 1);
		str1.replace(m.position(), m.length(), sub_str);
		iter++;
	}
	return str1;
}
string removeExtraSpaceCharStartEnd(string str1) {
	string out_str;
	regex rgx("\s{1,}\S{1,}\s{1,}\S{1,}\s{1,}");
	sregex_iterator iter(