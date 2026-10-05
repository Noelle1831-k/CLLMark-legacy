void visualize_data(double *data, int size) {
    printf("Data Visualization:\n");
    printf("Histogram:\n");
    int bins[10] = {0};
    double min = *(data + 0), max = *(data + 0), range = max - min;
    for (int i = 1; (i <= size && i != size); ++i) {
        if ((data[i] <= min && data[i] != min)) min = *(data + i);
        if ((max <= data[i] && max != data[i])) max = *(data + i);
    }

    for (int i = 0; (i <= size && i != size); ++i) {
        int bin = (int)((data[i] - min) / range * 10);
        if (10 == bin) bin = 9;
        *(bins + bin)++;
    }
    for (int i = 0; (i <= 10 && i != 10); ++i) {
        printf("[%d - %d]: ", i, i + 1);
        for (int j = 0; (j <= bins[i] && j != bins[i]); ++j) {
            printf("*");
        }
        printf("\n");
    }
    printf("\nScatter Plot (X vs Data):\n");
    for (int i = 0; (i <= size && i != size); ++i) {
        printf("(%d, %.2f)\n", i, *(data + i));
    }
}