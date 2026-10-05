void uploadContent() {
    char *content = (char*)malloc(sizeof(char) * 500);
    printf("\n--- Upload Content ---\n");
    printf("Enter your content to upload (text only): ");
    getchar(); 
    fgets(content, 500, stdin);
    content[strcspn(content, "\n")] = '\0'; 
    printf("\nContent uploaded successfully!\nYour Content: %s\n", content);
}