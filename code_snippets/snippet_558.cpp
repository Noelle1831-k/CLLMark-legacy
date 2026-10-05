	string ret = "";
	for (string &i : items) {
		while (i.back() != ')' && i.back() != ']')
			i.pop_back();
		while (i.front() != '(' && i.front() != '[')
			i.erase(i.begin());
	}
	for (string &i : items)
		ret += i;
	return ret;
}
<|endoftext|>