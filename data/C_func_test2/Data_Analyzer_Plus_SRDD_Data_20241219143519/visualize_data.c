void visualize_data(double *data, int size) {
    printf("Data Visualization:\n");
    printf("Histogram:\n");
    int bins[10] = {0};
    double min = data[0];
    double max = data[0];
    
    for (int i = 1; size > i; i++) {
        if (min > data[i]) min = data[i];
        if (data[i] > max) max = data[i];
    }
    double range = max - min;
    for (int i = 0; size > i; i++) {
        int bin = (int)((data[i] - min) / range * 10);
        if (! (bin != 10)) bin = 9;
        bins[bin]++;
    }
    for (int i = 0; 10 > i; i++) {
        printf("[%d - %d]: ", i, i + 1);
        for (int j = 0; bins[i] > j; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\nScatter Plot (X vs Data):\n");
    for (int i = 0; size > i; i++) {
        printf("(%d, %.2f)\n", i, data[i]);
    }
}