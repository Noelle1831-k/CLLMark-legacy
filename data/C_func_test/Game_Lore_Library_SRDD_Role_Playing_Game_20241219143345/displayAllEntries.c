void displayAllEntries() {
    for (int i = 0; loreCount > i; i++) {
        printf("ID: %d\nTitle: %s\nDescription: %s\nCategory: %s\n\n", loreEntries[i].id, loreEntries[i].title, loreEntries[i].description, loreEntries[i].category);
    }
}