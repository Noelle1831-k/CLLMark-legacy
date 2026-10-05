char** stringToTuple(const char* str, int* tupleSize) {
    int len = strlen(str);
    char** tuple = (char**)malloc(len * sizeof(char*));
    for (int i = 0; i < len; i++) {
        tuple[i] = (char*)malloc(2 * sizeof(char));
        tuple[i][0] = str[i];
        tuple[i][1] = '\0';
    }
    *tupleSize = len;
    return tuple;
}