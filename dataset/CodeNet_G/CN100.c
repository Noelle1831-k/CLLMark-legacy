#define MAX_EMPLOYEES 4000
void identify_good_workers() {
    int n, i, id, p, q;
    long long sales[MAX_EMPLOYEES] = {0};
    int ids[MAX_EMPLOYEES], index = 0, printed = 0;
    while (scanf("%d", &n), n != 0) {
        long long threshold = 1000000;
        for (int j = 0; j < n; j++) {
            scanf("%d %d %d", &id, &p, &q);
            int k;
            for (k = 0; k < index; k++) {
                if (ids[k] == id) break;
            }
            if (k == index) {
                ids[index++] = id;
            }
            sales[k] += (long long)p * q;
        }
        printed = 0;
        for (int j = 0; j < index; j++) {
            if (sales[j] >= threshold) {
                printf("%d ", ids[j]);
                printed = 1;
            }
            sales[j] = 0;  
        }
        if (!printed) {
            printf("NA");
        }
        printf("\n");
        index = 0;  
    }
}
