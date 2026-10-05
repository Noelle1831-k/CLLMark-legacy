	int size = arr.size();
	int i, j, k;
	int first, second, third;
	int firstSecond;
	int firstSecondSecond;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			for (k = j + 1; k < size; k++) {
				first = arr[i];
				second = arr[j];
				third = arr[k];
				firstSecond = first * second;
				firstSecondSecond = firstSecond * third;
				if (firstSecondSecond > firstSecond) {
					return vector<int>({first, second});
				}
			}
		}
	}
	return vector<int>();
}
using namespace std;
