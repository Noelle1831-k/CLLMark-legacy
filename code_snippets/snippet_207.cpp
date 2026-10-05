	unsigned i = 0;
	while (n) {
		i += n & 1;
		n >>= 1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n /= 2;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n -= n & (-n);
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i++;
		n &= n - 1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n %= n - 1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i++;
		n -= n & n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i++;
		n &= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n *= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n ^= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n <<= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n |= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n &= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n -= n & n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n *= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n /= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n %= n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n -= n & n-1;
	}
	return i;
}
int countSetBits(int n) {
	unsigned i = 0;
	while (n) {
		i += n & 1;
		n *= n-1;
	}
	return i;
}
/**
 * Write a c++ function to count set bits