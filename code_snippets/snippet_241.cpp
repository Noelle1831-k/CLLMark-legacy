	vector<int> res{};
	for (int i = 0; i < testTup1.size(); i++) {
		res.push_back(testTup1[i] / testTup2[i]);
	}
	return res;
}
int main() {
	std::cout << "Hello World!" << std::endl; 
	return 0;
}
<|endoftext|>