void viewProfile() {
    char name[50];
    printf("Enter your name to view profile: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("\n--- Profile ---\n");
            printf("Name: %s\n", users[i].name);
            printf("Bio: %s\n", users[i].bio);
            printf("Favorite Recipes: %d\n", users[i].recipeCount);
            return;
        }
    }
    printf("User not found.\n");
}