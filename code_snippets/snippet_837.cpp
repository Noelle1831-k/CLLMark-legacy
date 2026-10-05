	map<char, int> roman_values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
	int result = 0;
	char prev = s[0];
	for (int i = 1; i < s.length(); i++) {
		char curr = s[i];
		if (roman_values[prev] < roman_values[curr]) {
			result -= roman_values[prev];
		} else {
			result += roman_values[prev];
		}
		prev = curr;
	}
	result += roman_values[prev];
	return result;
}
int main() {
	string roman = "MMMCMXCIX";
	cout << romanToInt(roman);
	return 0;
}
<|endoftext|>