typedef struct {
    int element;
    int count;
} Frequency;
int compare(const void *a, const void *b) {
    return ((Frequency *)a)->element - ((Frequency *)b)->element;
}
void freqElement(int arr[], int size) {
    Frequency *frequency = (Frequency *)malloc(size * sizeof(Frequency));
    int frequencyCount = 0;
    for (int i = 0; i < size; i++) {
        int found = 0;
        for (int j = 0; j < frequencyCount; j++) {
            if (frequency[j].element == arr[i]) {
                frequency[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            frequency[frequencyCount].element = arr[i];
            frequency[frequencyCount].count = 1;
            frequencyCount++;
        }
    }
    qsort(frequency, frequencyCount, sizeof(Frequency), compare);
    printf("{");
    for (int i = 0; i < frequencyCount; i++) {
        printf("%d: %d", frequency[i].element, frequency[i].count);
        if (i < frequencyCount - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    free(frequency);
}