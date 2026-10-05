typedef struct {
    char** keys;
    int* values;
    size_t size;
} Dictionary;
Dictionary createDictionary(const char** keys, const int* values, size_t size) {
    Dictionary dict;
    dict.keys = (char**)malloc(size * sizeof(char*));
    dict.values = (int*)malloc(size * sizeof(int));
    dict.size = size;
    for (size_t i = 0; i < size; i++) {
        dict.keys[i] = strdup(keys[i]);
        dict.values[i] = values[i];
    }
    return dict;
}
void freeDictionary(Dictionary dict) {
    for (size_t i = 0; i < dict.size; i++) {
        free(dict.keys[i]);
    }
    free(dict.keys);
    free(dict.values);
}
const char* accessKey(Dictionary dict, int index) {
    if (index < 0 || index >= dict.size) {
        return NULL;
    }
    return dict.keys[index];
}