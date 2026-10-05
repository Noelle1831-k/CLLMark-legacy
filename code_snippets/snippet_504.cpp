	while(l<=r){
		int m = l+(r-l)/2;
		if (a * n < m*(m+1)) {
			r = m-1;
		}
		else {
			l = m+1;
		}
	}
	return l;
}
int main() {
	int a, n, l, r;
	a = 2;
	n = 3;
	l = 1;
	r = 10;
	cout<<countNo(a, n, l, r);
	return 0;
}
<|endoftext|>