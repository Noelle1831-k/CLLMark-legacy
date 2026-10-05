	vector<int> res;
	for(auto it: dict)
		res.push_back(it.first);
	return res;
}
int countOccurrence(vector<int> list, int target) {
	int count = 0;
	for(auto x: list)
		if(x == target)
			count++;
	return count;
}
int countOccurrenceWithDuplicates(vector<int> list, int target) {
	int count = 0;
	for(auto x: list)
		if(x == target)
			count++;
	return count;
}
int countOccurrenceWithDuplicates(vector<int> list, int target) {
	int count = 0;
	for(auto x: list)
		if(x == target)
			count++;
	return count;
}
int countOccurrenceWithDuplicates(vector<int> list, int target) {
	int count = 0;
	for(auto x: list)
		if(x == target)
			count++;
	return count;
}
int countOccurrenceWithDuplicates(vector<int> list, int target) {
	int count = 0;
	for(auto x: list)
		if(x == target)
			count++;
	return count;
}
/**
 * Write a function to count the occurrence of an element in a list in a way that allows duplicates.
 * > countOccurrenceWithDuplicates([1, 2, 3, 4, 5, 1, 2, 3, 4, 5], 1)
 * 3
 * > countOccurrenceWithDuplicates([1, 2, 3, 4, 5, 1, 2, 3, 4, 5], 2)
 * 3
 *