	double result = 1;
	k = min(k, n - k); 
	for (int i = 0; i < k; i++) {
		result *= n - i;
		result /= i + 1;
		result *= p;
	}
	return result;
}
int main() {
	return 0;
}
<|endoftext|>