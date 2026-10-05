	int i = 0, j = n - 1;
	while (i < j) {
		while (i < j && arr[i] > 0) {
			i++;
		}
		while (i < j && arr[j] < 0) {
			j--;
		}
		if (i < j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	return arr;
}
int main() {
	std::cout << reArrange({ -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 }, 10) << std::endl;
	std::cout << reArrange({ 1, 2, 3, -4, -1, 4 }, 6) << std::endl;
	std::cout << reArrange({ 4, 7, 9, 77, -4, 5, -3, -9 }, 8) << std::endl;
	return 0;
}
<|endoftext|>