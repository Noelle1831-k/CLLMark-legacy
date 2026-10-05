int* getKey(int keys[], char* values[], int size) {
    int* key_list = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        key_list[i] = keys[i];
    }
    return key_list;
}