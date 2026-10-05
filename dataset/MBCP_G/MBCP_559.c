int maxSubArraySum(int* a, int size) {
    int max_so_far = a[0];
    int current_max = a[0];
    for (int i = 1; i < size; i++) {
        current_max = (a[i] > (current_max + a[i])) ? a[i] : (current_max + a[i]);
        max_so_far = (max_so_far > current_max) ? max_so_far : current_max;
    }
    return max_so_far;
}