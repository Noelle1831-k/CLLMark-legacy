	int bell[n+1];
	bell[0] = bell[1] = 1;
	for(int i=2;i<=n;i++) {
		for(int j=i;j>0;j--) {
			bell[j] = bell[j] + bell[j-1];
		}
	}
	return bell[n];
}
int main() {
	int n = 4;
	cout << "bell(" << n << ") = " << bellNumber(n) << endl;
	return 0;
}
<|endoftext|>