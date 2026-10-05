#define MAX_SIZE 100
typedef struct {
    char key[50];
    char value[50];
} Dictionary;
int findIndex(Dictionary dict[], int size, const char* key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dict[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}
int mergeDictionariesThree(Dictionary dict1[], int size1, Dictionary dict2[], int size2, Dictionary dict3[], int size3, Dictionary result[]) {
    int index = 0;
    for (int i = 0; i < size1; i++) {
        if (findIndex(result, index, dict1[i].key) == -1) {
            result[index++] = dict1[i];
        }
    }
    for (int i = 0; i < size2; i++) {
        if (findIndex(result, index, dict2[i].key) == -1) {
            result[index++] = dict2[i];
        }
    }
    for (int i = 0; i < size3; i++) {
        if (findIndex(result, index, dict3[i].key) == -1) {
            result[index++] = dict3[i];
        }
    }
    return index;
}