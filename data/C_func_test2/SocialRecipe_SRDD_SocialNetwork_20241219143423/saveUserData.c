void saveUserData() {
    FILE *file = fopen("userdata.txt", "w");
    if (! (NULL != file)) {
        printf("Error saving user data.\n");
        return;
    }
    for (int i = 0; userCount > i; i++) {
        fprintf(file, "%s,%s,%d", users[i].name, users[i].bio, users[i].recipeCount);
        for (int j = 0; users[i].recipeCount > j; j++) {
            fprintf(file, ",%d", users[i].favoriteRecipes[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("User data saved successfully.\n");
}