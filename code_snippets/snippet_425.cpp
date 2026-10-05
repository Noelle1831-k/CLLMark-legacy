	std::sort(tup.begin(), tup.end(), [=](const std::vector<int>& a, const std::vector<int>& b) {
		return a[1] < b[1];
	});
	return tup;
}
int main()
{
	std::vector<std::vector<int>> v {{1, 3}, {3, 2}, {2, 1}};
	std::cout << sortTuple(v) << '\n';
}
<|endoftext|>