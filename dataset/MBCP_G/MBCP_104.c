int compare(const void* a, const void* b) {
    const char** strA = (const char**)a;
    const char** strB = (const char**)b;
    return strcmp(*strA, *strB);
}
void sortSublists(char*** inputList, int numLists, int* listSizes) {
    for (int i = 0; i < numLists; ++i) {
        qsort(inputList[i], listSizes[i], sizeof(char*), compare);
    }
}