	string expression = "[0-9a-zA-Z]$";
	string::const_iterator found = find_if(str.begin(), str.end(), [=](const char ch) {
		return regex_search(str.c_str(), expression);
	});
	string ret = "Accept";
	if (found != str.end())
		ret = "Discard";
	return ret;
}
int main() {
	string str("dawood@");
	string ret = checkAlphanumeric(str);
	cout << ret << endl;
	str = "skdmsam326";
	ret = checkAlphanumeric(str);
	cout << ret << endl;
	str = "cooltricks@";
	ret = checkAlphanumeric(str);
	cout << ret << endl;
	return 0;
}
<|endoftext|>