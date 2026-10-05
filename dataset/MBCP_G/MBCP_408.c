typedef struct {
    int first;
    int second;
    int sum;
} Pair;
int comparePairs(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    return pairA->sum - pairB->sum;
}
Pair* kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize) {
    *returnSize = 0;
    int totalPairs = nums1Size * nums2Size;
    Pair *pairs = (Pair *)malloc(totalPairs * sizeof(Pair));
    for (int i = 0; i < nums1Size; ++i) {
        for (int j = 0; j < nums2Size; ++j) {
            pairs[*returnSize].first = nums1[i];
            pairs[*returnSize].second = nums2[j];
            pairs[*returnSize].sum = nums1[i] + nums2[j];
            (*returnSize)++;
        }
    }
    qsort(pairs, totalPairs, sizeof(Pair), comparePairs);
    if (k < *returnSize) {
        *returnSize = k;
    }
    return pairs;
}