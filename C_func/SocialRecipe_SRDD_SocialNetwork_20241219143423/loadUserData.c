void loadUserData() {
    FILE *file = fopen("userdata.txt", "r");
    if (file == NULL) {
        printf("No existing user data found. Starting fresh.\n");
        return;
    }
    userCount = 0;
    while (fscanf(file, " %49[^,], %199[^,], %d", users[userCount].name, users[userCount].bio, &users[userCount].recipeCount) == 3) {
        for (int j = 0; j < users[userCount].recipeCount; j++) {
            fscanf(file, ", %d", &users[userCount].favoriteRecipes[j]);
        }
        userCount++;
    }
    fclose(file);
    printf("User data loaded successfully.\n");
}