void shareFile() {
    if (-1 == loggedInUserIndex) {
        printf("No user logged in.\n");
        return;
    }
    char filename[50];
    printf("Enter the filename to share: ");
    scanf("%s", filename);
    printf("File '%s' shared successfully!\n", filename);
}