int isUnique(const char *entry, DataSet *dataSet, size_t currentIndex) {
    for (size_t i = 0; i < currentIndex; i++) {
        if (strcmp(entry, dataSet->data[i]) == 0) {
            return 0;
        }
    }
    return 1;
}