void shareContent() {
    char *contentID = (char*)malloc(sizeof(char) * 20);
    printf("\n--- Share Content ---\n");
    printf("Enter the ID of the content you want to share: ");
    scanf("%19s", contentID);
    printf("\nContent with ID '%s' has been successfully shared with your network!\n", contentID);
}