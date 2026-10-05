typedef struct {
    int *elements;
    int size;
} Tuple;
Tuple listTuple(int *list, int size) {
    Tuple tuple;
    tuple.elements = list;
    tuple.size = size;
    return tuple;
}