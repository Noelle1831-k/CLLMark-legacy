void commentContent() {
    char contentID[20];
    char comment[300];
    printf("\n--- Comment on Content ---\n");
    printf("Enter the ID of the content to comment on: ");
    scanf("%19s", contentID);
    printf("Enter your comment: ");
    getchar(); 
    fgets(comment, 300, stdin);
    comment[strcspn(comment, "\n")] = '\0'; 
    printf("\nYour comment has been added to content with ID: %s\nComment: %s\n", contentID, comment);
}