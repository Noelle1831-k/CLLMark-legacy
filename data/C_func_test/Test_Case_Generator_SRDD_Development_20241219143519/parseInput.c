ParsedData* parseInput(const char *input) {
    ParsedData *data = (ParsedData *)malloc(sizeof(ParsedData));
    if (data == NULL) {
        return NULL;
    }
    data->functionName = strdup("exampleFunction");
    data->numParameters = 2;
    data->parameterTypes = (char **)malloc(2 * sizeof(char *));
    data->parameterTypes[0] = strdup("int");
    data->parameterTypes[1] = strdup("char*");
    return data;
}