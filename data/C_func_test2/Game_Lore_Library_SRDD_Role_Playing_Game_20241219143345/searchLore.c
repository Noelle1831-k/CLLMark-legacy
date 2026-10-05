void searchLore() {
    char keyword[100];
    printf("Enter keyword to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0; 
    printf("Searching for lore entries containing '%s'...\n", keyword);
    int results = searchEntriesByKeyword(keyword);
    if (results == 0) {
        printf("No matching lore entries found.\n");
    }
}