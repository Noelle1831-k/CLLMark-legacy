#define MAX_KEYS 100
typedef struct {
    char key[50];
    int value;
} Dict;
int addDict(Dict d1[], int size1, Dict d2[], int size2, Dict result[]) {
    int resultIndex = 0;
    int found;
    for (int i = 0; i < size1; i++) {
        found = 0;
        for (int j = 0; j < resultIndex; j++) {
            if (strcmp(result[j].key, d1[i].key) == 0) {
                result[j].value += d1[i].value;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(result[resultIndex].key, d1[i].key);
            result[resultIndex].value = d1[i].value;
            resultIndex++;
        }
    }
    for (int i = 0; i < size2; i++) {
        found = 0;
        for (int j = 0; j < resultIndex; j++) {
            if (strcmp(result[j].key, d2[i].key) == 0) {
                result[j].value += d2[i].value;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(result[resultIndex].key, d2[i].key);
            result[resultIndex].value = d2[i].value;
            resultIndex++;
        }
    }
    return resultIndex;
}