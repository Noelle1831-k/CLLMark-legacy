	int count_even = 0, count_odd = 0;
	while (n != 0) {
		count_even += (n % 10) % 2;
		count_odd += n % 10 > 0;
		n /= 10;
	}
	return count_even * 2 != count_odd;
}
int main() {
	cout << isDiff(1212112) << endl;
	cout << isDiff(1212) << endl;
	return 0;
}
<|endoftext|>