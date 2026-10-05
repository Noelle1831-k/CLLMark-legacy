	std::sort(list1.begin(), list1.end());
	std::vector<int> res;
	std::for_each(list1.begin(), list1.end(), [n, &res](int i) {
		if (n <= 0)
		{
			return;
		}
		res.push_back(i);
		n--;
	});
	return res;
}
int main() {
	std::cout << smallNnum(vector<int>{10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100}, 2) << std::endl;
	std::cout << smallNnum(vector<int>{10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100}, 5) << std::endl;
	std::cout << smallNnum(vector<int>{10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100}, 3) << std::endl;
	return 0;
}
<|endoftext|>