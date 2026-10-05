void unionElements(int *arr1, int size1, int *arr2, int size2, int *result, int *resultSize) {
    int hash[1000] = {0}; 
    for (int i = 0; i < size1; i++) {
        hash[arr1[i]] = 1;
    }
    for (int i = 0; i < size2; i++) {
        hash[arr2[i]] = 1;
    }
    int index = 0;
    for (int i = 0; i < 1000; i++) {
        if (hash[i] == 1) {
            result[index++] = i;
        }
    }
    *resultSize = index;
}