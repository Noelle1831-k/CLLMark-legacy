	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] > arr[high]) low = mid + 1;
		else high = mid;
	}
	return arr[low];
}
int main()
{
	int arr[] = { 2, 3, 5, 6, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("%dn", findMax(arr, 0, n - 1));
	return 0;
}
<|endoftext|>