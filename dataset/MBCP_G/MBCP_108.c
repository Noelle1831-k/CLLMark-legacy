int* mergeSortedList(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3, int* returnSize) {
    int totalSize = size1 + size2 + size3;
    int* mergedArray = (int*)malloc(totalSize * sizeof(int));
    *returnSize = totalSize;
    int i = 0, j = 0, k = 0, m = 0;
    while (i < size1 && j < size2 && k < size3) {
        if (arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) {
            mergedArray[m++] = arr1[i++];
        } else if (arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) {
            mergedArray[m++] = arr2[j++];
        } else {
            mergedArray[m++] = arr3[k++];
        }
    }
    while (i < size1 && j < size2) {
        mergedArray[m++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
    }
    while (i < size1 && k < size3) {
        mergedArray[m++] = (arr1[i] <= arr3[k]) ? arr1[i++] : arr3[k++];
    }
    while (j < size2 && k < size3) {
        mergedArray[m++] = (arr2[j] <= arr3[k]) ? arr2[j++] : arr3[k++];
    }
    while (i < size1) {
        mergedArray[m++] = arr1[i++];
    }
    while (j < size2) {
        mergedArray[m++] = arr2[j++];
    }
    while (k < size3) {
        mergedArray[m++] = arr3[k++];
    }
    return mergedArray;
}