	while (x > 0) {
		if (x % 10 != 0 && x % 10 % 2 == 0) {
			x = x/10;
		} else if (x % 10 != 0 && x % 10 % 2 == 1) {
			x = x/10;
		} else {
			return false;
		}
	}
	return true;
}
int main() {
	int x = 14;
	cout << isNumKeith(x) << endl;
}
<|endoftext|>