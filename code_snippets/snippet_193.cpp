	string regexDecimal = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]*)?$";
	string regexDecimalWithTwoPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{2})?$";
	string regexDecimalWithThreePrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{3})?$";
	string regexDecimalWithFourPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{4})?$";
	string regexDecimalWithFivePrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{5})?$";
	string regexDecimalWithSixPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{6})?$";
	string regexDecimalWithSevenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{7})?$";
	string regexDecimalWithEightPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{8})?$";
	string regexDecimalWithNinePrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{9})?$";
	string regexDecimalWithTenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{10})?$";
	string regexDecimalWithElevenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{11})?$";
	string regexDecimalWithTwelvePrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{12})?$";
	string regexDecimalWithThirteenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{13})?$";
	string regexDecimalWithFourteenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{14})?$";
	string regexDecimalWithFifteenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{15})?$";
	string regexDecimalWithSixteenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{16})?$";
	string regexDecimalWithSeventeenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{17})?$";
	string regexDecimalWithEighteenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{18})?$";
	string regexDecimalWithNineteenPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{19})?$";
	string regexDecimalWithTwentyPrecision = "^(0|(-(0|([1-9][0-9]*))))?((0|[1-9][0-9]*))?(\.[0-9]{20})?$";
	if (regex_match(num, regexDecimalWithTwoPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithThreePrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithFourPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithFivePrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithSixPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithSevenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithEightPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithNinePrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithTenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithElevenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithTwelvePrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithThirteenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithFourteenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithFifteenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithSixteenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithSeventeenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithEighteenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithNineteenPrecision)) {
		return true;
	}
	else if (regex_match(num, regexDecimalWithTwentyPrecision)) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	string example1 = "123.11";
	string example2 = "0.21";
	string example3 = "123.1214";
	cout << isDecimal(example1) << endl;
	cout << isDecimal(example2) << endl;
	cout << isDecimal(example3) << endl;
}
<|endoftext|>