int canArrange(int *arr) {
    int bMax = 0, cMax = 0;
    for (int i = 0; i < 10; i++) {
        if (bMax <= cMax) {
            if (arr[i] < bMax) return 0;
            bMax = arr[i];
        } else {
            if (arr[i] < cMax) return 0;
            cMax = arr[i];
        }
    }
    return 1;
}
void processDataSet(int dataSets, int numbers[dataSets][10]) {
    for (int i = 0; i < dataSets; i++) {
        if (canArrange(numbers[i])) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}