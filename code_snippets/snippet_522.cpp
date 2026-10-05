	string original = to_string(number);
	string calculated = original;
	while(number != 0){
		calculated += to_string(number%10);
		number = number/10;
	}
	calculated = calculated.substr(calculated.size()-original.size());
	return original == calculated;
}
<|endoftext|>