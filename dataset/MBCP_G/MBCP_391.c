typedef struct InnerDict {
    char *key;
    int value;
} InnerDict;
typedef struct OuterDict {
    char *key;
    InnerDict innerDict;
} OuterDict;
OuterDict* convertListDictionary(const char *l1[], const char *l2[], const int l3[], int size) {
    OuterDict* result = (OuterDict*)malloc(size * sizeof(OuterDict));
    for (int i = 0; i < size; ++i) {
        result[i].key = strdup(l1[i]);
        result[i].innerDict.key = strdup(l2[i]);
        result[i].innerDict.value = l3[i];
    }
    return result;
}