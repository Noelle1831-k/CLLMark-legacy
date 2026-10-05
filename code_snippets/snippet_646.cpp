	unordered_map<int, int> res{};
	for (int i = 0; i < testTup.size() - 1; i += 2) {
		res[testTup[i]] = testTup[i + 1];
	}
	return res;
}
int main() {
	std::cout << "hello, world\n";
	return 0;
}
<|endoftext|>