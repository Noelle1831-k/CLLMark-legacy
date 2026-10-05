typedef struct {
    int key;
    int uniqueValues[100];
    int uniqueCount;
} KeyMapper;
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int contains(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1;
        }
    }
    return 0;
}
void getUnique(int arr[][2], int rows, char *result) {
    KeyMapper ;
    KeyMapper *map = (KeyMapper *)malloc(sizeof(KeyMapper) * 100);
    int mapSize = 0;
    for (int i = 0; i < rows; i++) {
        int val = arr[i][1];
        int key = arr[i][0];
        int idx = -1;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].key == val) {
                idx = j;
                break;
            }
        }
        if (idx == -1) {
            idx = mapSize;
            mapSize++;
            map[idx].key = val;
            map[idx].uniqueCount = 0;
        }
        if (!contains(map[idx].uniqueValues, map[idx].uniqueCount, key)) {
            map[idx].uniqueValues[(map[idx].uniqueCount)++] = key;
        }
    }
    qsort(map, mapSize, sizeof(KeyMapper), compare);
    sprintf(result, "{");
    for (int i = 0; i < mapSize; i++) {
        char *buffer = (char *)malloc(sizeof(char) * 50);
        sprintf(buffer, "%d: %d", map[i].key, map[i].uniqueCount);
        strcat(result, buffer);
        if (i < mapSize - 1) {
            strcat(result, ", ");
        }
    }
    strcat(result, "}");
}