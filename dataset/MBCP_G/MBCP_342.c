struct MinRange {
    int min;
    int max;
};
struct MinRange findMinimumRange(int** array, int* sizes, int k) {
    int* ptrs = (int*)calloc(k, sizeof(int));
    struct MinRange result = {INT_MAX, INT_MIN};
    int minX = INT_MAX;
    int maxX = INT_MIN;
    while (1) {
        int minIndex = -1;
        minX = INT_MAX;
        maxX = INT_MIN;
        for (int i = 0; i < k; i++) {
            if (ptrs[i] < sizes[i]) {
                if (array[i][ptrs[i]] < minX) {
                    minX = array[i][ptrs[i]];
                    minIndex = i;
                }
                if (array[i][ptrs[i]] > maxX) {
                    maxX = array[i][ptrs[i]];
                }
            }
        }
        if (minIndex == -1) break;
        if ((maxX - minX) < (result.max - result.min)) {
            result.min = minX;
            result.max = maxX;
        }
        ptrs[minIndex]++;
    }
    free(ptrs);
    return result;
}