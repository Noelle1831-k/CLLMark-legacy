	return 3.141592653589793238463 * degree / 180.0;
}
double degreeRadian(double radian) {
	return 180.0 * radian / 3.141592653589793238463;
}
int printTheSum(int* arr, int arrSize) {
	int sum = 0;
	for (int i = 0; i < arrSize; i++) {
		sum += arr[i];
	}
	printf("%d\n", sum);
	return sum;
}
int printTheSumUsingRecursion(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingRecursion(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
int printTheSumUsingEarlyStopping(int* arr, int arrSize) {
	if (arrSize == 0) {
		return 0;
	}
	return arr[arrSize - 1] + printTheSumUsingEarlyStopping(arr, arrSize - 1);
}
/**
 * Write a function to print the sum of the given array of integers using recursion and early stopping.
 * > printTheSumUsingEarlyStopping([1, 2, 3, 4, 5])