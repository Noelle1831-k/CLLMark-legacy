int maxSumSubseq(int* a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
    int secondLast = a[0];
    int last = (a[0] > a[1]) ? a[0] : a[1];
    for (int i = 2; i < n; i++) {
        int current = (a[i] + secondLast > last) ? a[i] + secondLast : last;
        secondLast = last;
        last = current;
    }
    return last;
}