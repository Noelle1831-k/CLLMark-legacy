void addHighlight() {
    if (highlightCount < MAX_HIGHLIGHTS) {
        printf("Enter highlight content: ");
        scanf(" %[^\n]s", highlights[highlightCount].content);
        highlightCount++;
        printf("Highlight added.\n");
    } else {
        printf("Highlight list is full.\n");
    }
}