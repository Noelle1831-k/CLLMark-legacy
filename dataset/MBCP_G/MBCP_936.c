typedef struct {
    int first;
    int second;
} Tuple;
void reArrangeTuples(Tuple testList[], int size, int ordList[]) {
    Tuple result[size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (testList[j].first == ordList[i]) {
                result[i] = testList[j];
                break;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        testList[i] = result[i];
    }
}