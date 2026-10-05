	std::sort(x.begin(), x.end());
    auto newVec = std::vector<int>();
	auto it = std::unique(x.begin(), x.end());
    newVec.assign(x.begin(), it);
    return newVec;
}
int main() {
	std::cout << repeat(vector<int>{10, 20, 30, 20, 20, 30, 40, 50, -20, 60, 60, -20, -20}) << std::endl;
	std::cout << repeat(vector<int>{-1, 1, -1, 8}) << std::endl;
	std::cout << repeat(vector<int>{1, 2, 3, 1, 2}) << std::endl;
}
<|endoftext|>