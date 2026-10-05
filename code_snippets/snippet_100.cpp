	int count = 0;
	for (int i = l; i <= r; i++) {
		string binary = to_string(i, base = 16);
		count += (1 << (4 * binary.size())) - 1;
	}
	return count;
}
int main(){
	cout << countHexadecimal(10, 15) << "\n";
	cout << countHexadecimal(2, 4) << "\n";
	cout << countHexadecimal(15, 16) << "\n";
	return 0;
}<|endoftext|>