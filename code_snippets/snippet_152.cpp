	if (num1 % 2 == 0 && num2 % 2 == 0)
		return num1 % num2 == 0;
	else if (num1 % 2 != 0 && num2 % 2 != 0)
		return num1 % num2 == 0;
	else
		return num1 % 2 == 0 && num2 % 2 != 0;
}
int main() {
	int num1, num2;
	cin >> num1 >> num2;
	if (areequivalent(num1, num2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
<|endoftext|>