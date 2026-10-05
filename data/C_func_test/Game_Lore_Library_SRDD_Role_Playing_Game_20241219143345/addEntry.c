void addEntry(const char *title, const char *description, const char *category) {
    loreEntries = realloc(loreEntries, sizeof(LoreEntry) * (loreCount + 1));
    LoreEntry *newEntry = &loreEntries[loreCount++];
    newEntry->id = generateID();
    strncpy(newEntry->title, title, sizeof(newEntry->title));
    strncpy(newEntry->description, description, sizeof(newEntry->description));
    strncpy(newEntry->category, category, sizeof(newEntry->category));
}