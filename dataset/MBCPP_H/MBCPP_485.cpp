    int max = 0;
    for(int i = 1; i < n - 1; i++) {
        if(a[i] > a[i - 1]) {
            if(a[i] > max) {
                max = a[i];
            }
        }
    }
    return max;
}