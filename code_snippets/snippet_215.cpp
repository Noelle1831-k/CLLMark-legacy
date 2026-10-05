	std::sort(list1.begin(), list1.end());
    list1.resize(n);
    return list1;
}
int main() {
	std::cout << largNnum(vector<int>{10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100}, 2) << std::endl;
	std::cout << largNnum(vector<int>{10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100}, 5) << std::endl;
	std::cout << largNnum(vector<int>{10, 20, 50, 70, 90, 20, 50, 40, 60, 80, 100}, 3) << std::endl;
	return 0;
}
<|endoftext|>