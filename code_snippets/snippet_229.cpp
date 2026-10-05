	vector<int> inter = {};
	# Write your code here
	sort(arrayNums1.begin(), arrayNums1.end());
	sort(arrayNums2.begin(), arrayNums2.end());
	arrayNums1.erase(unique(arrayNums1.begin(), arrayNums1.end()), arrayNums1.end());
	arrayNums2.erase(unique(arrayNums2.begin(), arrayNums2.end()), arrayNums2.end());
	std::set_intersection(arrayNums1.begin(), arrayNums1.end(), arrayNums2.begin(), arrayNums2.end(), std::back_inserter(inter));
	return inter;
}
int main() {
	# Write your code here
	vector<int> inter = intersectionArray(vector<int>{1, 2, 3, 5, 7, 8, 9, 10}, vector<int>{1, 2, 4, 8, 9});
	for (int i = 0; i < inter.size(); i++) {
		cout << inter[i] << " ";
	}
}
<|endoftext|>