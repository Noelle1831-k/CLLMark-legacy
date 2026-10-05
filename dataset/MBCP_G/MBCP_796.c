typedef struct {
    char *key;
    int value;
} KeyValuePair;
int returnSum(KeyValuePair dict[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += dict[i].value;
    }
    return sum;
}
