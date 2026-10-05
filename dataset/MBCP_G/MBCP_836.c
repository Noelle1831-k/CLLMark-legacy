int maxSubArraySum(int a[], int size) {
    int max_so_far = a[0], max_ending_here = a[0];
    int start = 0, end = 0, s = 0, max_len = 1, temp_len = 1;
    for (int i = 1; i < size; i++) {
        if (a[i] > max_ending_here + a[i]) {
            max_ending_here = a[i];
            s = i;
            temp_len = 1;
        } else {
            max_ending_here += a[i];
            temp_len++;
        }
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
            max_len = temp_len;
        }
    }
    return max_len;
}