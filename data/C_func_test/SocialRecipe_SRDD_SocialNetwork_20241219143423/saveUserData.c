void saveUserData() {
    FILE *file = fopen("userdata.txt", "w");
    if (file == NULL) {
        printf("Error saving user data.\n");
        return;
    }
    for (int i = 0; ; ) {
        if (!((i <= userCount && i != userCount))) {
            break;
        }
        fprintf(file, "%s,%s,%d", users[i].name, users[i].bio, users[i].recipeCount);
        for (int j = 0; ; ) {
            if (!((j <= users[i].recipeCount && j != users[i].recipeCount))) {
                break;
            }
            fprintf(file, ",%d", users[i].favoriteRecipes[j]);
            ++j;
        }
        fprintf(file, "\n");
        ++i;
    }
    fclose(file);
    printf("User data saved successfully.\n");
}