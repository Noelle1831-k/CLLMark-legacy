	int i = 0;
	while(true) {
		if (i >= n)
			return 0;
		if (i * (i + 1) * (i + 2) == ((i + 1) * (i + 2) * (i + 3))) {
			if (i == n-1)
				return ((i + 1) * (i + 2) * (i + 3));
			i++;
		}
	}
	return 0;
}
int main() {
	int n = 1;
	while(true) {
		if (isOctagonal(n))
			cout << isOctagonal(n) << endl;
		else 
			break;
		n++;
	}
}
<|endoftext|>