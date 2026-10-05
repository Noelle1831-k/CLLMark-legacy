	auto func = [] (int i) {
		return i % 2 == 0;
	};
	int count = 0;
	for (int i = 0; i < arrayNums.size(); i++) {
		if (func(arrayNums[i])) {
			count++;
		}
	}
	return count;
}
int main() {
	vector<int> arrayNums;
	arrayNums.push_back(1);
	arrayNums.push_back(2);
	arrayNums.push_back(3);
	arrayNums.push_back(5);
	arrayNums.push_back(7);
	arrayNums.push_back(8);
	arrayNums.push_back(9);
	arrayNums.push_back(10);
	printf("Number of even elements: %d\n", countEven(arrayNums));
	arrayNums.clear();
	arrayNums.push_back(10);
	arrayNums.push_back(15);
	arrayNums.push_back(14);
	arrayNums.push_back(13);
	arrayNums.push_back(-18);
	arrayNums.push_back(12);
	arrayNums.push_back(-20);
	printf("Number of even elements: %d\n", countEven(arrayNums));
	arrayNums.clear();
	arrayNums.push_back(1);
	arrayNums.push_back(2);
	arrayNums.push_back(4);
	arrayNums.push_back(8);
	arrayNums.push_back(9);
	printf("Number of even elements: %d\n", countEven(arrayNums));
	return 0;
}
<|endoftext|>