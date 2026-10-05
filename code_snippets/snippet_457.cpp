	int size = arr.size();
	vector<int> lis_up(size, 1), lis_down(size, 1);
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && lis_up[i] < lis_up[j] + 1) lis_up[i] = lis_up[j] + 1;
		}
	}
	for (int i = size - 2; i >= 0; i--) {
		for (int j = size - 1; j > i; j--) {
			if (arr[i] > arr[j] && lis_down[i] < lis_down[j] + 1) lis_down[i] = lis_down[j] + 1;
		}
	}
	int result = 0;
	for (int i = 0; i < size; i++) {
		result = max(result, lis_up[i] + lis_down[i] - 1);
	}
	return result;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cout << lbs(vector<int>{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}) << std::endl;
	std::cout << lbs(vector<int>{1, 11, 2, 10, 4, 5, 2, 1}) << std::endl;
	std::cout << lbs(vector<int>{80, 60, 30, 40, 20, 10}) << std::endl;
	return 0;
}
<|endoftext|>