	string binary;
	while(n>0){
		string binary;
		binary = n%2 + binary;
		n=n/2;
	}
	return stoi(binary);
}
<|endoftext|>