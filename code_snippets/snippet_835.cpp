	string roman = "";
	string roman_values[] = {
		"M",
		"CM",
		"D",
		"CD",
		"C",
		"XC",
		"L",
		"XL",
		"X",
		"IX",
		"V",
		"IV",
		"I"
	};
	int roman_values_int[] = {
		1000,
		900,
		500,
		400,
		100,
		90,
		50,
		40,
		10,
		9,
		5,
		4,
		1
	};
	int i;
	for (i = 0; i < 13; i++) {
		while (num >= roman_values_int[i]) {
			num -= roman_values_int[i];
			roman += roman_values[i];
		}
	}
	return roman;
}
int main() {
	string roman = intToRoman(4444);
	cout << roman << endl;
	return 0;
}
<|endoftext|>