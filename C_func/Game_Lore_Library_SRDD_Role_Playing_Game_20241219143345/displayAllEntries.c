void displayAllEntries() {
    for (int i = 0; i < loreCount; i++) {
        printf("ID: %d\nTitle: %s\nDescription: %s\nCategory: %s\n\n", loreEntries[i].id, loreEntries[i].title, loreEntries[i].description, loreEntries[i].category);
    }
}