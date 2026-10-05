	string vowels = "";
	for (std::size_t i = 0; i < str1.length(); ++i) {
		if (string("aeiouAEIOU").find(str1[i]) != -1) {
			vowels += str1[i];
		}
	}
	string rresult = "";
	for (std::size_t i = 0; i < str1.length(); ++i) {
		if (string("aeiouAEIOU").find(str1[i]) != -1) {
			rresult += vowels[vowels.length() - 1];
			vowels = vowels.substr(0, vowels.length() - 1);
		} else {
			rresult += str1[i];
		}
	}
	return rresult;
}