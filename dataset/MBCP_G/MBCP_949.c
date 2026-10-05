int countDigits(int num) {
    int count = 0;
    if (num == 0) return 1;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
int totalDigitsInTuple(int *arr, int size) {
    int totalDigits = 0;
    for (int i = 0; i < size; i++) {
        totalDigits += countDigits(arr[i]);
    }
    return totalDigits;
}
int compareTuples(const void *a, const void *b, void *arg) {
    int sizeA = *((int*)arg + *(int*)a);
    int sizeB = *((int*)arg + *(int*)b);
    int *listA = *(int**)a;
    int *listB = *(int**)b;
    int digitsA = totalDigitsInTuple(listA, sizeA);
    int digitsB = totalDigitsInTuple(listB, sizeB);
    return digitsA - digitsB;
}
void sortList(int **list, int *sizes, int length) {
    qsort_r(list, length, sizeof(int*), compareTuples, sizes);
}
void printList(int **list, int *sizes, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("(");
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d", list[i][j]);
            if (j < sizes[i] - 1) printf(", ");
        }
        printf(")");
        if (i < length - 1) printf(", ");
    }
    printf("]\n");
}