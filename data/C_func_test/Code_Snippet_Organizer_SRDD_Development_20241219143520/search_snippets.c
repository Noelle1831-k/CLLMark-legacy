void search_snippets() {
    char keyword[100];
    printf("Enter keyword to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; 
    printf("\nSearch Results:\n");
    for (int i = 0; i < snippet_count; i++) {
        if (strstr(snippets[i].title, keyword) || strstr(snippets[i].code, keyword)) {
            printf("Title: %s\n", snippets[i].title);
            printf("Code:\n%s\n", snippets[i].code);
            printf("\n");
        }
    }
}