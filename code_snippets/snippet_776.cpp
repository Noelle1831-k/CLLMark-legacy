	for (int i = 0; i < lists.size(); i++) {
		lists[i].swap(lists[i].back(), lists[i].front());
	}
	return lists;
}
int main() {
	std::cout << reverseListLists({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}) << std::endl;
	std::cout << reverseListLists({{1, 2}, {2, 3}, {3, 4}}) << std::endl;
	std::cout << reverseListLists({{10, 20}, {30, 40}}) << std::endl;
	return 0;
}
<|endoftext|>