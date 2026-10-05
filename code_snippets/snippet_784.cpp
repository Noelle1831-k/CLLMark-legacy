	vector<int> res;
	int i = 0;
	while(i < numbers.size()){
		while(i < numbers.size() && numbers[i] != numbers[i-1])
			i++;
		if(i >= numbers.size())
			break;
		while(i < numbers.size() && numbers[i] == numbers[i-1])
			i++;
		res.push_back(numbers[i-1]);
	}
	return res;
}
int main(){
 	vector<int> test = {1, 1, 3, 4, 4, 5, 6, 7};
 	assert(extractElements(test, 2) == {1, 4});
 	test = {0, 1, 2, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 4) == {4});
 	test = {0, 0, 0, 0, 0};
 	assert(extractElements(test, 5) == {0});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 5) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 8) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 9) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 10) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 11) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 12) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 13) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 14) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 15) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 16) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 17) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 18) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 19) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 20) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 21) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 22) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 23) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 24) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 25) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 26) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 27) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 28) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 29) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 30) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 4, 5, 7};
 	assert(extractElements(test, 31) == {2, 3, 4, 5, 7});
 	test = {2, 2, 3, 3, 4, 4, 4, 