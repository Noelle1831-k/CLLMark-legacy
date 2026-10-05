void shareArticle() {
    printf("\n--- Share an Article ---\n");
    printf("Enter the article you want to share: ");
    char article[256];
    scanf(" %[^\n]s", article);
    printf("Enter the recipient's email: ");
    char email[100];
    scanf(" %[^\n]s", email);
    if (validateEmail(email)) {
        printf("Sharing article: '%s' with %s\n", article, email);
        printf("Article shared successfully.\n");
    } else {
        printf("Invalid email address. Please try again.\n");
    }
}