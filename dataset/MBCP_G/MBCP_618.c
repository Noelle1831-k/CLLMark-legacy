double* divList(int* nums1, int len1, int* nums2, int len2, int* resultLen) {
    if (len1 != len2) {
        *resultLen = 0;
        return NULL;
    }
    *resultLen = len1;
    double* result = (double*)malloc(len1 * sizeof(double));
    for (int i = 0; i < len1; i++) {
        if (nums2[i] != 0) {
            result[i] = (double)nums1[i] / nums2[i];
        } else {
            result[i] = 0.0; 
        }
    }
    return result;
}