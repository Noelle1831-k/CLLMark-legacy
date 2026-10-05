void frequency_distribution(float heights[], int n) {
    int frequency[6] = {0};
    for (int i = 0; i < n; i++) {
        if (heights[i] < 165.0) {
            frequency[0]++;
        } else if (heights[i] < 170.0) {
            frequency[1]++;
        } else if (heights[i] < 175.0) {
            frequency[2]++;
        } else if (heights[i] < 180.0) {
            frequency[3]++;
        } else if (heights[i] < 185.0) {
            frequency[4]++;
        } else {
            frequency[5]++;
        }
    }
    for (int i = 0; i < 6; i++) {
        printf("%d:", i + 1);
        for (int j = 0; j < frequency[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}