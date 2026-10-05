void highlightText() {
    if (highlightCount >= MAX_HIGHLIGHTS) {
        printf("Highlight limit reached.\n");
        return;
    }
    printf("Enter text to highlight: ");
    scanf(" %[^\n]%*c", highlights[highlightCount].text);
    printf("Text highlighted: %s\n", highlights[highlightCount].text);
    highlightCount++;
}