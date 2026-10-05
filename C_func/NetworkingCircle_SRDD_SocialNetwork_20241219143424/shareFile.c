void shareFile() {
    if (loggedInUserIndex == -1) {
        printf("No user logged in.\n");
        return;
    }
    char filename[50];
    printf("Enter the filename to share: ");
    scanf("%s", filename);
    printf("File '%s' shared successfully!\n", filename);
}