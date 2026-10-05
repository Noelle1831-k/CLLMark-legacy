typedef struct {
    int key;
    int value;
} KeyValuePair;
bool isKeyPresent(KeyValuePair d[], int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (d[i].key == x) {
            return true;
        }
    }
    return false;
}