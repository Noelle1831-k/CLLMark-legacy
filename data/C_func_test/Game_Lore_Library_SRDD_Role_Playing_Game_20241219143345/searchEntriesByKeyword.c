int searchEntriesByKeyword(const char *keyword) {
    int found = 0;
    for (int i = 0; i < loreCount; i++) {
        if (strstr(loreEntries[i].title, keyword) || strstr(loreEntries[i].description, keyword)) {
            printf("ID: %d\nTitle: %s\nDescription: %s\nCategory: %s\n\n", loreEntries[i].id, loreEntries[i].title, loreEntries[i].description, loreEntries[i].category);
            found++;
        }
    }
    return found;
}