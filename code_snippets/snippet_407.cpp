	string out;
	while (decinum) {
		out += to_string(decinum % 8);
		decinum /= 8;
	}
	reverse(out.begin(), out.end());
	return stoi(out);
}
<|endoftext|>