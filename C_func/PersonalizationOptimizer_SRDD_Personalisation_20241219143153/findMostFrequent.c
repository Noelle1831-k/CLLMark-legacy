char* findMostFrequent(char **array, int size) {
    if (array == NULL || size <= 0) return NULL;
    int maxCount = 0;
    char *mostFrequent = NULL;
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(array[i], array[j]) == 0) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            if (mostFrequent != NULL) {
                free(mostFrequent);
            }
            mostFrequent = strdup(array[i]); 
        }
    }
    return mostFrequent;
}