	while(n and not (n & n-1)) {
		n /= 2;
	}
	return n == 0 ? 1 : n * 2;
}
int count_ones(int n) {
	int count = 0;
	while(n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}
int count_zeros(int n) {
	return 32 - count_ones(n);
}
int count_ones2(int n) {
	int count = 0;
	while(n) {
		count += (n & 1);
		n >>= 1;
	}
	return count;
}
int count_zeros2(int n) {
	return 32 - count_ones2(n);
}
int count_ones3(int n) {
	int count = 0;
	while(n) {
		count += (n & 1);
		n /= 2;
	}
	return count;
}
int count_zeros3(int n) {
	return 32 - count_ones3(n);
}
int count_ones4(int n) {
	int count = 0;
	while(n) {
		count++;
		n /= 2;
	}
	return count;
}
int count_zeros4(int n) {
	return 32 - count_ones4(n);
}
int count_ones5(int n) {
	int count = 0;
	while(n) {
		count++;
		n &= (n-1);
	}
	return count;
}
int count_zeros5(int n) {
	return 32 - count_ones5(n);
}
int count_ones6(int n) {
	int count = 0;
	while(n) {
		count++;
		n -= n & (-n);
	}
	return count;
}
int count_zeros6(int n) {
	return 32 - count_ones6(n);
}
int count_ones7(int n) {
	int count = 0;
	while(n) {
		count++;
		n -= n & n-1;
	}
	return count;
}
int count_zeros7(int n) {
	return 32 - count_ones7(n);
}
int count_ones8(int n) {
	int count = 0;
	while(n) {
		count++;
		n /= 2;
	}
	return count;
}
int count_zeros8(int n) {
	return 32 - count_ones8(n);
}
int count_ones9(int n) {
	int count = 0;
	while(n) {
		count += (n & 1);
		n /= 2;
	}
	return count;
}
int count_zeros9(int n) {
	return 32 - count_ones9(n);
}
int count_ones10(int n) {
	int count = 0;
	while(n) {
		count += (n & 1);
		n = n >> 1;
	}
	return count;
}
int count_zeros10(int n) {
	return 32 - count_ones10(n);
}
int count_ones11(int n) {
	int count = 0;
	while(n) {
		count += (n & 1);
		n %= 2;
	}
	return count;
}
int count_zeros11(int n)