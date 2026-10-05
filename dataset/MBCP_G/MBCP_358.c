int* moddivList(int* nums1, int* nums2, int size, int* resultSize) {
    int* result = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = nums1[i] % nums2[i];
    }
    *resultSize = size;
    return result;
}