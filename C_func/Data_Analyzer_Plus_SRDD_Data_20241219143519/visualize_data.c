void visualize_data(double *data, int size) {
    printf("Data Visualization:\n");
    printf("Histogram:\n");
    int bins[10] = {0};
    double min = data[0], max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }
    double range = max - min;
    for (int i = 0; i < size; i++) {
        int bin = (int)((data[i] - min) / range * 10);
        if (bin == 10) bin = 9;
        bins[bin]++;
    }
    for (int i = 0; i < 10; i++) {
        printf("[%d - %d]: ", i, i + 1);
        for (int j = 0; j < bins[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\nScatter Plot (X vs Data):\n");
    for (int i = 0; i < size; i++) {
        printf("(%d, %.2f)\n", i, data[i]);
    }
}