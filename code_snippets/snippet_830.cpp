	int result = 1; 
    if (r > n-r)
        r = n-r; 
    for (int i = 0; i < r; ++i) {
        result = (result * (n - i)) % p;
        result = (result * (i + 1)) % p;
    }
    return result;
}
int main() {
	int result = ncrModP(18, 14, 19);
	cout << result << endl;
	return 0;
}
<|endoftext|>