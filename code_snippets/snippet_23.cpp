	int decimal = 0;
	int i = 0;
	while(binary){
		decimal += (binary&1) * pow(2, i);
		binary = binary>>1;
		i++;
	}
	return decimal;
}
<|endoftext|>