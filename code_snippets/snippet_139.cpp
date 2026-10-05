	map<int, int> mp;
	mp[arr[0]] = 1;
	int count = 1;
	int result = 1;
	for (int i = 1; i < n; i++) {
		count = mp[arr[i]] + 1;
		mp[arr[i]] = count;
		result = max(result, count);
	}
	return result;
}
int count(int arr[], int n, int key, int occur) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			if (arr[i] == occur) count++;
		}
	}
	return count;
}
int printSum(int arr[]) {
	int sum = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		sum += arr[i];
	}
	return sum;
}
int printSumUsingForEach(int arr[]) {
	int sum = 0;
	for (int i : arr) {
		sum += i;
	}
	return sum;
}
int printSumUsingForEachAndLambda(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += i;
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithAuxiliaryMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += auxSum(i);
	});
	return sum;
}
int auxSum(int i) {
	return i;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
int printSumUsingForEachAndLambdaWithLambdaMethod(int arr[]) {
	int sum = 0;
	for_each(arr, [sum](int i) {
		sum += [i](int i) {
			return i;
		};
	});
	return sum;
}
/**
 * Write a program to print the sum of the given array using for-each and lambda function and an auxiliary method
 * > printSumUsingForEachAndLambdaWithLambdaMethod(int[])
 * 16
