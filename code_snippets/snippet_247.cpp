	return ((int)k[0]);
}
void add(int* k, int m) {
	k[7] = m;
}
void printSum(int* k) {
	int i = 0;
	int sum = 0;
	while (i < 8) {
		sum = sum + k[i];
		i = i + 1;
	}
	cout << sum << ", ";
}
int printSumUsingRecursion(int* k) {
	int i = 0;
	int sum = 0;
	if (i >= 8) {
		return sum;
	} else {
		sum = sum + k[i];
		i = i + 1;
		return sum + printSumUsingRecursion(k);
	}
}
void printSumUsingRecursionAndSum(int* k) {
	int i = 0;
	int sum = 0;
	if (i >= 8) {
		cout << sum << ", ";
	} else {
		sum = sum + k[i];
		i = i + 1;
		printSumUsingRecursionAndSum(k);
		cout << sum << ", ";
	}
}
void printSumUsingForAndSum(int* k) {
	int i = 0;
	int sum = 0;
	for (i = 0; i < 8; i++) {
		sum = sum + k[i];
	}
	cout << sum << ", ";
}
void printSumUsingFor(int* k) {
	int i = 0;
	int sum = 0;
	for (i = 0; i < 8; i++) {
		sum = sum + k[i];
		cout << sum << ", ";
	}
}
void printSumUsingForAndRecursion(int* k) {
	int i = 0;
	int sum = 0;
	for (i = 0; i < 8; i++) {
		sum = sum + k[i];
		printSumUsingForAndRecursion(k);
		cout << sum << ", ";
	}
}
void printSumUsingForAndRecursionAndSum(int* k) {
	int i = 0;
	int sum = 0;
	for (i = 0; i < 8; i++) {
		sum = sum + k[i];
		printSumUsingForAndRecursionAndSum(k);
		cout << sum << ", ";
	}
}
void printSumUsingForAndRecursionAndSumUsingFor(int* k) {
	int i = 0;
	int sum = 0;
	for (i = 0; i < 8; i++) {
		sum = sum + k[i];
		printSumUsingForAndRecursionAndSumUsingFor(k);
		cout << sum << ", ";
	}
}
/**
 * Write a function to print the sum of the given array of integers using for.
 * > printSumUsingForAndRecursionAndSumUsingForAndRecursion(int[])
 * 8, [1, 2, 3, 4, 5]
 * > printSumUsingForAndRecursionAndSumUsingForAndRecursion(int[])
 * 8, [1, 2, 3, 4, 5, 8]
 * > printSumUsingForAndRecursionAndSumUsingForAndRecursion(int[])
 * 8, [1, 2, 3, 4, 5