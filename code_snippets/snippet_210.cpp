	int m = a;
	if(b < m)
		m = b;
	if(c < m)
		m = c;
	return m;
}
bool isSorted(int* arr, int arrLength) {
	if(arrLength <= 1)
		return true;
	int i = 0;
	while(i < arrLength - 1) {
		if(arr[i] > arr[i + 1])
			return false;
		i++;
	}
	return true;
}
void printAllSubArr(int* arr1, int arr1Length, int* arr2, int arr2Length, int* arr3, int arr3Length) {
	if(arr1Length <= 0 && arr2Length <= 0 && arr3Length <= 0) {
		cout << endl;
		return;
	}
	printAllSubArr(arr1, arr1Length - 1, arr2, arr2Length - 1, arr3, arr3Length - 1);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2, arr2Length - 1, arr3, arr3Length - 1);
	printAllSubArr(arr1, arr1Length - 1, arr2 + 1, arr2Length - 1, arr3, arr3Length - 1);
	printAllSubArr(arr1, arr1Length - 1, arr2, arr2Length - 1, arr3 + 1, arr3Length - 1);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2, arr2Length - 1, arr3 + 1, arr3Length - 1);
	printAllSubArr(arr1, arr1Length - 1, arr2 + 1, arr2Length - 1, arr3 + 1, arr3Length - 1);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2 + 1, arr2Length - 1, arr3, arr3Length - 1);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2, arr2Length - 1, arr3 + 1, arr3Length - 1);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2 + 1, arr2Length - 1, arr3 + 1, arr3Length - 1);
	printAllSubArr(arr1, arr1Length, arr2, arr2Length, arr3, arr3Length - 1);
	printAllSubArr(arr1, arr1Length, arr2 + 1, arr2Length, arr3, arr3Length - 1);
	printAllSubArr(arr1, arr1Length, arr2, arr2Length, arr3 + 1, arr3Length - 1);
	printAllSubArr(arr1, arr1Length, arr2 + 1, arr2Length, arr3 + 1, arr3Length - 1);
	printAllSubArr(arr1, arr1Length - 1, arr2, arr2Length, arr3, arr3Length);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2, arr2Length, arr3, arr3Length);
	printAllSubArr(arr1, arr1Length - 1, arr2 + 1, arr2Length, arr3, arr3Length);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2 + 1, arr2Length, arr3, arr3Length);
	printAllSubArr(arr1, arr1Length - 1, arr2, arr2Length, arr3 + 1, arr3Length);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2, arr2Length, arr3 + 1, arr3Length);
	printAllSubArr(arr1, arr1Length - 1, arr2 + 1, arr2Length, arr3 + 1, arr3Length);
	printAllSubArr(arr1 + 1, arr1Length - 1, arr2 + 1, arr2Length, arr3 + 1, arr3Length);
	printAllSubArr(arr1, arr1Length, arr2, arr2Length - 1, arr3, arr3Length);
	printAllSubArr(arr1, arr1Length, arr2 + 1, arr2Length - 1, arr3, arr3Length);
	printAllSubArr(arr1, arr1Length, arr2, arr2Length - 1, arr3 + 1, arr3Length);
	printAllSubArr(arr1, arr1Length, arr2 + 1, arr2Length - 1, arr3 + 1, arr3Length);
	printAllSubArr(arr1, arr1Length, arr2, arr2Length, arr3, arr3Length);
	printAllSubArr(arr1, arr1Length, arr2 + 1, arr2Length, arr3, arr3Length);
	printAllSubArr(arr1, arr1Length, arr2, arr2Length, arr3 + 1, arr3Length);
	printAllSubArr(