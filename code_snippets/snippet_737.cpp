	map<int, int> mymap; 
	map<int, int>::iterator it; 
	for(int i = 0; i < n; i++) {
		mymap[arr[i]]++;
		mymap[dep[i]]--;
	}
	int count = 0;
	it = mymap.begin();
	while(it != mymap.end()) {
		count = max(count, it->second);
		it++;
	}
	return count;
}
int main()
{
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findPlatform(arr, dep, n);
	return 0;
}
<|endoftext|>