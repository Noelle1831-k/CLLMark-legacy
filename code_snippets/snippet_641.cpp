	string binary;
	while (n != 0) {
		binary = to_string(n % 2) + binary;
		n /= 2;
	}
	string firstBit = binary[0];
	string lastBit = binary[binary.length() - 1];
	string tobeFlipped = "";
	for (int i = 1; i < binary.length() - 1; i++) {
		if (binary[i] == '1') {
			tobeFlipped += '0';
		} else {
			tobeFlipped += '1';
		}
	}
	string tobeFlippedAndFirstAndLastBit = firstBit + tobeFlipped + lastBit;
	string tobeFlippedAndFirstAndLastBitInInteger = stoi(tobeFlippedAndFirstAndLastBit, nullptr, 2);
	return tobeFlippedAndFirstAndLastBitInInteger;
}
<|endoftext|>