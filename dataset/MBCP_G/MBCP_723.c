int countSamePair(int* nums1, int size1, int* nums2, int size2) {
    int count = 0;
    for (int i = 0; i < size1 && i < size2; i++) {
        if (nums1[i] == nums2[i]) {
            count++;
        }
    }
    return count;
}