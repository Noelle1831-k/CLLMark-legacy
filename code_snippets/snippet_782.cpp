	std::sort(tuples.begin(), tuples.end(), [=](const auto &l, const auto &r) {
		return l.back() < r.back();
	});
	return tuples;
}
int main() {
	std::cout << sortListLast({{2, 5}, {1, 2}, {4, 4}, {2, 3}, {2, 1}}) << std::endl;
	std::cout << sortListLast({{9, 8}, {4, 7}, {3, 5}, {7, 9}, {1, 2}}) << std::endl;
	std::cout << sortListLast({{20, 50}, {10, 20}, {40, 40}}) << std::endl;
}
<|endoftext|>