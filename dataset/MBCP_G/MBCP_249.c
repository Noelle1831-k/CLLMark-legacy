void intersectionArray(int* arrayNums1, int size1, int* arrayNums2, int size2, int* intersection, int* intersectionSize) {
    int i, j;
    *intersectionSize = 0;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (arrayNums1[i] == arrayNums2[j]) {
                intersection[*intersectionSize] = arrayNums1[i];
                (*intersectionSize)++;
                break;
            }
        }
    }
}