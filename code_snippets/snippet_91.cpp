	double result = 0;
	for (int i = 0; i < numbers.size(); i++) {
		result += numbers[i];
	}
	return result / numbers.size();
}
int main() {
	vector<int> input{8, 2, 3, -1, 7};
	cout << multiplyNum(input) << endl;
	return 0;
}
<|endoftext|>