	vector<int> res;
	for (int i = startnum; i <= endnum; i++) {
		string tmp = to_string(i);
		int tmpnum = 0;
		for (int j = 0; j < tmp.length(); j++) {
			if (i % tmp[j] != 0) {
				break;
			} else {
				tmpnum += 1;
			}
		}
		if (tmpnum == tmp.length()) {
			res.push_back(i);
		}
	}
	return res;
}
int main() {
	cout << divisibleByDigits(1, 22) << endl;
	cout << divisibleByDigits(1, 15) << endl;
	cout << divisibleByDigits(20, 25) << endl;
	return 0;
}
<|endoftext|>