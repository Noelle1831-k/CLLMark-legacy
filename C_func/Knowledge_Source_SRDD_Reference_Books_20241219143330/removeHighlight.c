void removeHighlight() {
    char content[MAX_HIGHLIGHT_LENGTH];
    printf("Enter highlight content to remove: ");
    scanf(" %[^\n]s", content);
    for (int i = 0; i < highlightCount; i++) {
        if (strcmp(highlights[i].content, content) == 0) {
            for (int j = i; j < highlightCount - 1; j++) {
                highlights[j] = highlights[j + 1];
            }
            highlightCount--;
            printf("Highlight removed.\n");
            return;
        }
    }
    printf("Highlight not found.\n");
}