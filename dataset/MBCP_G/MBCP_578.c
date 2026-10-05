int* interleaveLists(int* list1, int* list2, int* list3, int size) {
    int* result = (int*)malloc(sizeof(int) * size * 3);
    if (!result) return NULL; 
    for (int i = 0; i < size; i++) {
        result[i * 3] = list1[i];
        result[i * 3 + 1] = list2[i];
        result[i * 3 + 2] = list3[i];
    }
    return result;
}