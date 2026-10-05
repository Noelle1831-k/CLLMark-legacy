typedef struct Tuple {
    int *elements;
    int size;
    int frequency;
} Tuple;
int compareTuples(const void *a, const void *b) {
    Tuple *tupleA = (Tuple *)a;
    Tuple *tupleB = (Tuple *)b;
    if (tupleA->size != tupleB->size) {
        return tupleA->size - tupleB->size;
    }
    for (int i = 0; i < tupleA->size; i++) {
        if (tupleA->elements[i] != tupleB->elements[i]) {
            return tupleA->elements[i] - tupleB->elements[i];
        }
    }
    return 0;
}
void assignFreq(int **testList, int listSize, int *listLengths) {
    Tuple *tuples = (Tuple *)malloc(listSize * sizeof(Tuple));
    for (int i = 0; i < listSize; i++) {
        tuples[i].elements = testList[i];
        tuples[i].size = listLengths[i];
        tuples[i].frequency = 1;
    }
    qsort(tuples, listSize, sizeof(Tuple), compareTuples);
    for (int i = 0; i < listSize - 1; i++) {
        if (compareTuples(&tuples[i], &tuples[i + 1]) == 0) {
            tuples[i + 1].frequency = tuples[i].frequency + 1;
            tuples[i].frequency = 0;
        }
    }
    printf("[");
    for (int i = 0; i < listSize; i++) {
        if (tuples[i].frequency > 0) {
            printf("(");
            for (int j = 0; j < tuples[i].size; j++) {
                printf("%d", tuples[i].elements[j]);
                if (j != tuples[i].size - 1) {
                    printf(", ");
                }
            }
            printf(", %d)", tuples[i].frequency);
            if (i != listSize - 1) {
                printf(", ");
            }
        }
    }
    printf("]");
    free(tuples);
}
