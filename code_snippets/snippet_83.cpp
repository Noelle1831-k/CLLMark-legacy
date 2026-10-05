	string binary = bitset<64>(n).to_string();
	string binary_reverse = bitset<64>(n).to_string();
	reverse(binary_reverse.begin(), binary_reverse.end());
	string binary_complement = "";
	string binary_complement_reverse = "";
	string binary_complement_reverse_reverse = "";
	for (int i = 0; i < binary.length(); i++) {
		if (binary[i] == '1') {
			binary_complement += '0';
			binary_complement_reverse += '1';
		} else {
			binary_complement += '1';
			binary_complement_reverse += '0';
		}
	}
	string binary_complement_reverse_reverse = binary_complement_reverse;
	reverse(binary_complement_reverse_reverse.begin(), binary_complement_reverse_reverse.end());
	int result = stoi(binary_complement, nullptr, 2);
	int result_reverse = stoi(binary_complement_reverse, nullptr, 2);
	int result_reverse_reverse = stoi(binary_complement_reverse_reverse, nullptr, 2);
	if (result > n)
		return stoi(binary_reverse, nullptr, 2);
	else if (result_reverse > n)
		return stoi(binary, nullptr, 2);
	else if (result_reverse_reverse > n)
		return stoi(binary_reverse, nullptr, 2);
	else
		return stoi(binary, nullptr, 2);
}
int main() {
	int n = 12;
	cout << closestNum(n) << endl;
	return 0;
}
<|endoftext|>