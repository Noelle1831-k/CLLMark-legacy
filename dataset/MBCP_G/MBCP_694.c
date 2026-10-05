int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void extractUnique(int ***map, int *mapSizes, int *result, int *resultSize, int mapCount) {
    int hashTable[100] = {0}; 
    *resultSize = 0;
    for (int i = 0; i < mapCount; i++) {
        for (int j = 0; j < mapSizes[i]; j++) {
            if (!hashTable[map[i][0][j]]) {
                result[(*resultSize)++] = map[i][0][j];
                hashTable[map[i][0][j]] = 1;
            }
        }
    }
    qsort(result, *resultSize, sizeof(int), compare);
}
