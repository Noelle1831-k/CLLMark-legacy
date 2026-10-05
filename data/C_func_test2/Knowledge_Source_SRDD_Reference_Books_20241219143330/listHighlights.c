void listHighlights() {
    printf("Highlights:\n");
    for (int i = 0; i < highlightCount; i++) {
        printf("%s\n", highlights[i].content);
    }
}