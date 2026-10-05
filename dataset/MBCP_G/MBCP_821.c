typedef struct {
    char *key;
    char *value;
} KeyValuePair;
typedef struct {
    KeyValuePair *pairs;
    size_t size;
} Dictionary;
Dictionary mergeDictionaries(Dictionary dict1, Dictionary dict2) {
    Dictionary result;
    result.size = dict1.size + dict2.size;
    result.pairs = (KeyValuePair *)malloc(result.size * sizeof(KeyValuePair));
    size_t index = 0;
    for (size_t i = 0; i < dict1.size; i++) {
        result.pairs[index].key = strdup(dict1.pairs[i].key);
        result.pairs[index].value = strdup(dict1.pairs[i].value);
        index++;
    }
    for (size_t i = 0; i < dict2.size; i++) {
        size_t j;
        for (j = 0; j < dict1.size; j++) {
            if (strcmp(dict1.pairs[j].key, dict2.pairs[i].key) == 0) {
                break;
            }
        }
        if (j == dict1.size) {
            result.pairs[index].key = strdup(dict2.pairs[i].key);
            result.pairs[index].value = strdup(dict2.pairs[i].value);
            index++;
        }
    }
    result.size = index;
    result.pairs = (KeyValuePair *)realloc(result.pairs, result.size * sizeof(KeyValuePair));
    return result;
}