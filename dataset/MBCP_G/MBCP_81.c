#define MIN(a, b) ((a) < (b) ? (a) : (b))
void zipTuples(int *tup1, int size1, int *tup2, int size2, int result[][2]) {
    int minSize = MIN(size1, size2);
    int maxSize = size1 > size2 ? size1 : size2;
    for (int i = 0; i < maxSize; i++) {
        result[i][0] = tup1[i];
        result[i][1] = tup2[i % minSize];
    }
}