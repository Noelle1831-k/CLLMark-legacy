void bookmarkSource() {
    printf("Bookmarking a new source...\n");
    char *source = (char*)malloc(sizeof(char) * 50);
    printf("Enter source name to bookmark: ");
    scanf("%s", source);
    printf("Source '%s' bookmarked successfully.\n", source);
}