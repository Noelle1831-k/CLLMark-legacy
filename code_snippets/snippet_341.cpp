	int low = 0, high = a.size() - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (mid < high && a[mid] > a[mid + 1]) {
			return mid + 1;
		}
		if (mid > low && a[mid] < a[mid - 1]) {
			return mid;
		}
		if (a[low] > a[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return 0;
}
int main(int argc, char** argv) {
	return 0;
}
<|endoftext|>