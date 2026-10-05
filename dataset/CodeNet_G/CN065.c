#define MAX_COMPANIES 1000
typedef struct {
    int c;
    int totalCount;
} Company;
int compare(const void* a, const void* b) {
    Company* companyA = (Company*)a;
    Company* companyB = (Company*)b;
    return companyA->c - companyB->c;
}
void trackTransactionData(char* thisMonthData, char* lastMonthData) {
    int thisMonth[MAX_COMPANIES] = {0};
    int lastMonth[MAX_COMPANIES] = {0};
    int customerCounts = 0;
    Company results[MAX_COMPANIES];
    char* token;
    char* linePointer;
    token = strtok_r(thisMonthData, "\n", &linePointer);
    while (token != NULL) {
        int c, d;
        sscanf(token, "%d,%d", &c, &d);
        thisMonth[c - 1]++;
        token = strtok_r(NULL, "\n", &linePointer);
    }
    token = strtok_r(lastMonthData, "\n", &linePointer);
    while (token != NULL) {
        int c, d;
        sscanf(token, "%d,%d", &c, &d);
        lastMonth[c - 1]++;
        token = strtok_r(NULL, "\n", &linePointer);
    }
    for (int i = 0; i < MAX_COMPANIES; i++) {
        if (thisMonth[i] > 0 && lastMonth[i] > 0) {
            results[customerCounts].c = i + 1;
            results[customerCounts].totalCount = thisMonth[i] + lastMonth[i];
            customerCounts++;
        }
    }
    qsort(results, customerCounts, sizeof(Company), compare);
    for (int i = 0; i < customerCounts; i++) {
        printf("%d %d\n", results[i].c, results[i].totalCount);
    }
}