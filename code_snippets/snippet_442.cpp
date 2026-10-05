	int i = 0, j = a.size() - 1;
	while (i < j) {
		if (a[i] == 0) {
			a[i] = a[j];
			a[j] = 0;
			j--;
		}
		else {
			i++;
		}
	}
	return a;
}
int main() {
	std::cout << "Reordered Array: " << "[";
	for (int i : reOrder({6, 0, 8, 2, 3, 0, 4, 0, 1})) {
		std::cout << i << ", ";
	}
	std::cout << "]";
	std::cout << std::endl;
}
<|endoftext|>