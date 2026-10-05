char** newTuple(char** testList, int listSize, char* testStr) {
    char** result = (char**)malloc((listSize + 1) * sizeof(char*));
    for (int i = 0; i < listSize; i++) {
        result[i] = strdup(testList[i]);
    }
    result[listSize] = strdup(testStr);
    return result;
}
void freeTuple(char** tuple, int size) {
    for (int i = 0; i < size; i++) {
        free(tuple[i]);
    }
    free(tuple);
}
