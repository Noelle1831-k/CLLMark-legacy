void findClosest(int a[], int b[], int c[], int p, int q, int r, int result[]) {
    int i = 0, j = 0, k = 0;
    int min_diff = __INT_MAX__;
    while (i < p && j < q && k < r) {
        int max_elem = (a[i] > b[j]) ? ((a[i] > c[k]) ? a[i] : c[k]) : ((b[j] > c[k]) ? b[j] : c[k]);
        int min_elem = (a[i] < b[j]) ? ((a[i] < c[k]) ? a[i] : c[k]) : ((b[j] < c[k]) ? b[j] : c[k]);
        if (max_elem - min_elem < min_diff) {
            min_diff = max_elem - min_elem;
            result[0] = a[i];
            result[1] = b[j];
            result[2] = c[k];
        }
        if (min_diff == 0) break;
        if (a[i] == min_elem) {
            i++;
        } else if (b[j] == min_elem) {
            j++;
        } else {
            k++;
        }
    }
}
