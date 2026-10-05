int findPlatform(int arr[], int dep[], int n) {
    int platform_needed = 0, max_platforms = 0;
    int i = 0, j = 0;
    for (int k = 0; k < n-1; k++) {
        for (int l = 0; l < n-k-1; l++) {
            if (arr[l] > arr[l+1]) {
                int temp = arr[l];
                arr[l] = arr[l+1];
                arr[l+1] = temp;
            }
            if (dep[l] > dep[l+1]) {
                int temp = dep[l];
                dep[l] = dep[l+1];
                dep[l+1] = temp;
            }
        }
    }
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platform_needed++;
            i++;
            if (platform_needed > max_platforms) {
                max_platforms = platform_needed;
            }
        } else {
            platform_needed--;
            j++;
        }
    }
    return max_platforms;
}