	int result = 0; 
	while (n != 0) {
		result += n % 10; 
		n /= 10; 
	}
	return result;
}
int main() {
	int num1, num2;
	cin >> num1 >> num2;
	cout << sumDigits(num1) + sumDigits(num2) << endl;
	return 0;
}
<|endoftext|>