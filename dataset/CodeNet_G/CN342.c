int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
double maximize_rational_expression(int nums[], int n) {
    qsort(nums, n, sizeof(int), compare);
    double max_value = -(1.0 / 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    int A = nums[i], B = nums[j], C = nums[k], D = nums[l];
                    if (C - D != 0) {
                        double value = (double)(A + B) / (C - D);
                        if (value > max_value) {
                            max_value = value;
                        }
                    }
                }
            }
        }
    }
    return max_value;
}