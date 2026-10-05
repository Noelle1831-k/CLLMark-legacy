int counts[10];
void process_ice_cream_sales(int n, int sales[]) {
    for (int i = 0; i < 10; i++) {
        counts[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        counts[sales[i]]++;
    }
    for (int i = 0; i < 10; i++) {
        if (counts[i] == 0) {
            printf("-\n");
        } else {
            for (int j = 0; j < counts[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}