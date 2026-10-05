	string binary;
	string out;
	for (int i = 0; i < str.length(); i++) {
		char s = str[i];
		if (s == '0' || s == '1') {
			binary = binary + s;
		}
	}
	for (int i = 0; i < binary.length(); i++) {
		char s = binary[i];
		if (s == '0' && binary[i - 1] == '1') {
			out = "No";
			break;
		}
	}
	if (out == "") {
		out = "Yes";
	}
	return out;
}
<|endoftext|>