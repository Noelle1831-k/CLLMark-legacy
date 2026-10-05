typedef struct {
    int *elements;
    int size;
} Tuple;
Tuple setToTuple(int *set, int setSize) {
    Tuple tuple;
    tuple.elements = (int *)malloc(setSize * sizeof(int));
    tuple.size = setSize;
    for (int i = 0; i < setSize; ++i) {
        tuple.elements[i] = set[i];
    }
    return tuple;
}