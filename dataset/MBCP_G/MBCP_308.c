int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
int* largeProduct(int* nums1, int size1, int* nums2, int size2, int n) {
    int totalSize = size1 * size2;
    int *products = (int *)malloc(totalSize * sizeof(int));
    int index = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            products[index++] = nums1[i] * nums2[j];
        }
    }
    qsort(products, totalSize, sizeof(int), compare);
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = products[i];
    }
    free(products);
    return result;
}