	string out = "";
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] % 2 == 0) {
			out += str1[i];
		}
	}
	return out;
}
int main() {
	string out = removeOdd(string("language"));
	cout << out << endl;
	return 0;
}
<|endoftext|>