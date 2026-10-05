char** stringListToTuple(const char* str, int* length) {
    *length = strlen(str);
    char** tuple = (char**)malloc((*length) * sizeof(char*));
    for(int i = 0; i < *length; i++) {
        tuple[i] = (char*)malloc(2 * sizeof(char));
        tuple[i][0] = str[i];
        tuple[i][1] = '\0';
    }
    return tuple;
}