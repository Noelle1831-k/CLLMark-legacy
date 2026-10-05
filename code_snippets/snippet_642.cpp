	int low = 0, high = a.size();
	while(low < high) {
		int mid = (low + high) / 2;
		if(a[mid] > x) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}
int main() {
	assert(leftInsertion(vector<int>{1, 2, 4, 5}, 6) == 4);
	assert(leftInsertion(vector<int>{1, 2, 4, 5}, 3) == 2);
	assert(leftInsertion(vector<int>{1, 2, 4, 5}, 7) == 4);
	return 0;
}
<|endoftext|>