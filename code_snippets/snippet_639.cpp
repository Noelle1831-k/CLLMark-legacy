	int low = 0, high = a.size() - 1, middle;
	while (low <= high) {
		middle = low + (high - low) / 2;
		if (a[middle] == x) {
			while (middle - 1 >= 0 && a[middle - 1] == x) middle--;
			return middle;
		}
		else if (a[middle] < x) low = middle + 1;
		else high = middle - 1;
	}
	return -1;
}
int main() {
	std::cout << "1) Find the first occurrence of an element in a sorted array: " << std::endl;
	std::vector<int> myVec{2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
	std::cout << myVec[findFirstOccurrence(myVec, 5)] << std::endl; 
	std::vector<int> myVec1{2, 3, 5, 5, 6, 6, 8, 9, 9, 9};
	std::cout << myVec1[findFirstOccurrence(myVec1, 5)] << std::endl; 
	std::vector<int> myVec2{2, 4, 1, 5, 6, 6, 8, 9, 9, 9};
	std::cout << myVec2[findFirstOccurrence(myVec2, 6)] << std::endl; 
	return 0;
}
<|endoftext|>