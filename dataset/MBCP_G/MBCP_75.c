char* findTuples(int tuples[][3], int numTuples, int k) {
    char* result = (char*)malloc(1024 * sizeof(char));
    int offset = 0;
    offset += sprintf(result + offset, "[");
    for (int i = 0; i < numTuples; i++) {
        if (tuples[i][0] % k == 0 && tuples[i][1] % k == 0 && tuples[i][2] % k == 0) {
            if (offset > 1) {
                offset += sprintf(result + offset, ", ");
            }
            offset += sprintf(result + offset, "(%d, %d, %d)", tuples[i][0], tuples[i][1], tuples[i][2]);
        }
    }
    offset += sprintf(result + offset, "]");
    return result;
}