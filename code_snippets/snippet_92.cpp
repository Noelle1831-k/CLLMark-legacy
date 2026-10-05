	string binary;
	while(n>0){
		char b = n%2;
		binary = char(b) + binary;
		n /= 2;
	}
	return binary;
}
string binaryToDecimal(string binary) {
	string dec = "";
	string::iterator it;
	for(it = binary.begin(); it != binary.end(); it++){
		dec = dec + (*it - '0');
	}
	return dec;
}
string multiplyBinary(string binary1, string binary2) {
	string binary;
	string::iterator it1, it2;
	string::reverse_iterator rit1, rit2;
	for(it1 = binary1.begin(), it2 = binary2.begin(); it1 != binary1.end(); it1++, it2++){
		string dec1 = binaryToDecimal(string(it1, it1+1));
		string dec2 = binaryToDecimal(string(it2, it2+1));
		string dec = decimalToBinary(int(dec1) * int(dec2));
		string::iterator temp_it = binary.end();
		for(rit1 = dec.rbegin(), rit2 = binary.rbegin(); rit1 != dec.rend(); rit1++, rit2++){
			temp_it--;
			temp_it = temp_it - string(1, *rit1) + string(1, *rit2);
		}
		binary = temp_it - string(dec.begin(), dec.end());
	}
	return binary;
}
string multiplyBinary(string binary1, string binary2, string &rem){
	string binary;
	string::iterator it1, it2;
	string::reverse_iterator rit1, rit2;
	string::iterator temp_it = binary.end();
	string::reverse_iterator temp_rit = rem.rend();
	string::reverse_iterator temp_rit2 = rem.rend();
	for(it1 = binary1.begin(), it2 = binary2.begin(); it1 != binary1.end(); it1++, it2++){
		string dec1 = binaryToDecimal(string(it1, it1+1));
		string dec2 = binaryToDecimal(string(it2, it2+1));
		string dec = decimalToBinary(int(dec1) * int(dec2));
		string::iterator temp_it = binary.end();
		for(rit1 = dec.rbegin(), rit2 = binary.rbegin(); rit1 != dec.rend(); rit1++, rit2++){
			temp_it--;
			temp_it = temp_it - string(1, *rit1) + string(1, *rit2);
		}
		string::reverse_iterator temp_rit = rem.rend();
		string::reverse_iterator temp_rit2 = rem.rend();
		for(temp_rit = rem.rbegin(), temp_rit2 = rem.rbegin(); temp_rit != rem.rend(); temp_rit++, temp_rit2++){
			temp_rit = temp_rit - string(1, *temp_rit) + string(1, *temp_rit2);
		}
		temp_it = temp_it - string(dec.begin(), dec.end()) + string(temp_rit.begin(), temp_rit.end());
		temp_rit = temp_rit2;
	}
	rem = temp_rit2 - string(temp_rit.begin(), temp_rit.end());
	return binary;
}
string multiplyBinary(string binary1, string binary2, string &rem, string &rem1){
	string binary;
	string::iterator it1, it2;
	string::reverse_iterator rit1, rit2;
	string::iterator temp_it = binary.end();
	string::reverse_iterator temp_rit = rem.rend();
	string::reverse_iterator temp_rit2 = rem.rend();
	for(it1 = binary1.begin(), it2 = binary2.begin(); it1 != binary1.end(); it1++, it2++){
		string dec1 = binaryToDecimal(string(it1, it1+1));
		string dec2 = binaryToDecimal(string(it2, it2+1));
		string dec = decimalToBinary(int(dec1) * int(dec2));
		string::iterator temp_it = binary.end();
		for(rit1 = dec.rbegin(), rit2 = binary.rbegin(); rit1 != dec.rend(); rit1++, rit2++){
			temp_it--;
			temp_it = temp_it - string(1, *rit1) + string(1, *rit2);
		}
		string::reverse_iterator temp_rit = rem.rend();
		string::reverse_iterator temp_rit2 = rem.rend();
		for(temp_rit = rem.rbegin(), temp_rit2 = rem.rbegin(); temp_rit != rem.rend(); temp_rit++, temp_rit2++){
			temp_rit = temp_rit - string(1, *temp_rit) + string(1, *temp_rit2);
		}
		temp_it = temp_it - string(dec.begin(), dec.end()) + string(temp_rit.begin(), temp_rit.end());
		temp_rit = temp_rit2;
		string::reverse_iterator temp_rit = rem1.rend();
		string::reverse_iterator temp_rit2 = rem1.rend();
		for(temp_rit = rem1.rbegin(), temp_rit2 = rem1.rbegin(); temp_rit != rem1.rend(); temp_rit++, temp_rit2++){
			temp_rit = temp_rit - string(1, *temp_rit) + string(1, *temp_rit2);
		}
		temp_it = temp_it - string(string(it1, it1+1)) + string(temp_rit.begin(), temp_rit.end());
		temp_rit = temp_rit2;
	}
	rem = temp_rit2 - string(temp_rit.begin(), temp_rit.end());
	rem1 = temp_rit2 - string(temp_rit.begin(), temp_rit.end());
	return binary;
}
string multiplyBinary(string binary1, string binary2, string &rem, string &rem1, string &rem2){
	string binary;
	string::iterator it1, it2;
	string::reverse_iterator rit1, rit2;
	string::iterator temp_it = binary.end();
	string::reverse_iterator temp_rit = rem.rend();
	string::reverse_iterator temp_rit2 = rem.rend();
	for(it1 = binary1.begin(), it2 = binary2.begin(); it1 != binary1.end(); it1++, it2++){
		string dec1 = binaryToDecimal(string(it1, it1+1));
		string dec2 = binaryToDecimal(string(it2, it2+1));
		string dec = decimalToBinary(int(dec1) * int(dec2));
		string::iterator temp_it = binary.end();
		for(rit1 = dec.rbegin(), rit2 = binary.rbegin(); rit1 != dec.rend(); rit1++, rit2++){
			temp_it--;
			temp_it = temp_it - string(1, *rit1) + string(1, *rit2);
		}
		string::reverse_iterator temp_rit = rem.rend();
		string::reverse_iterator temp_rit2 = rem.rend();
		for(temp_rit = rem.rbegin(), temp_rit2 = rem.rbegin(); temp_rit != rem.rend(); temp_rit++, temp_rit2++){
			temp_rit = temp_rit - string(1, *temp_rit) + string(1, *temp_rit2);
		}
		temp_it = temp_it - string(dec.begin(), dec.end()) + string(temp_rit.begin(), temp_rit.end());
		temp_rit = temp_rit2;
		string::reverse_iterator temp_rit = rem1.rend();
		string::reverse_iterator temp_rit2 = rem1.rend();
		for(temp_