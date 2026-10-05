	unsigned int m = n >> d; 
	m <<= d; 
	m |= n; 
	m >>= d; 
	return m;
}
int main () {
	unsigned int n = 16;
	unsigned int d = 2;
	unsigned int m = n >> d; 
	m <<= d; 
	m |= n; 
	m >>= d; 
	cout << m << endl; 
	unsigned int n = 10;
	unsigned int d = 2;
	unsigned int m = n >> d; 
	m <<= d; 
	m |= n; 
	m >>= d; 
	cout << m << endl; 
	unsigned int n = 99;
	unsigned int d = 3;
	unsigned int m = n >> d; 
	m <<= d; 
	m |= n; 
	m >>= d; 
	cout << m << endl; 
	return 0;
}
<|endoftext|>