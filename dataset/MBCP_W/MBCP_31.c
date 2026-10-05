typedef struct {
    int value;
    int frequency;
} Element;
int compare(const void *a, const void *b) {
    Element *elementA = (Element *)a;
    Element *elementB = (Element *)b;
    if (elementB->frequency == elementA->frequency) 
        return elementA->value - elementB->value;
    return elementB->frequency - elementA->frequency;
}
void findTopK(int **lists, int *sizes, int numLists, int k, int *result) {
    int frequency[10000] = {0}; 
    for (int i = 0; i < numLists; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            frequency[lists[i][j]]++;
        }
    }
    Element ;
    Element *elements = (Element *)malloc(sizeof(Element) * 10000);
    int count = 0;
    for (int i = 0; i < 10000; i++) {
        if (frequency[i] > 0) {
            elements[count].value = i;
            elements[count].frequency = frequency[i];
            count++;
        }
    }
    qsort(elements, count, sizeof(Element), compare);
    for (int i = 0; i < k; i++) {
        result[i] = elements[i].value;
    }
}