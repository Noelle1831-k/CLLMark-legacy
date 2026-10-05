void createProfile() {
    char *username = (char*)malloc(sizeof(char) * 50);
    char *bio = (char*)malloc(sizeof(char) * 200);
    printf("\n--- Create Profile ---\n");
    printf("Enter your username: ");
    scanf("%49s", username);
    printf("Enter a short bio: ");
    getchar(); 
    fgets(bio, 200, stdin);
    *(bio + strcspn(bio, "\n")) = '\0'; 
    printf("\nProfile created successfully!\nUsername: %s\nBio: %s\n", username, bio);
}