void freeParsedData(ParsedData *data) {
    if (data) {
        free(data->functionName);
        for (int i = 0; i < data->numParameters; ++i) {
            free(data->parameterTypes[i]);
        }
        free(data->parameterTypes);
        free(data);
    }
}