int* addList(int* nums1, int* nums2, int size, int* result_size) {
    int* result = (int*)malloc(size * sizeof(int));
    if (result == NULL) {
        *result_size = 0;
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        result[i] = nums1[i] + nums2[i];
    }
    *result_size = size;
    return result;
}