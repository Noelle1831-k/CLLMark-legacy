	unsigned i = 1;
	while( i < n){
		i = i << 1;
	}
	return i >> 1;
}
int main() {
	std::cout << highestPowerOf2(10) <<std::endl;
	std::cout << highestPowerOf2(19) <<std::endl;
	std::cout << highestPowerOf2(32) <<std::endl;
	return 0;
}
<|endoftext|>