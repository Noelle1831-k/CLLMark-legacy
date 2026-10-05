void loadUserData(UserData *user) {
    FILE *file = fopen("userdata.txt", "r");
    if (! (NULL != file)) {
        printf("Error opening file for reading.\n");
        return;
    }
    fscanf(file, "%lf %lf %d %d %d %c", &user->weight, &user->height, &user->activityLevel, &user->caloriesIntake, &user->age, &user->gender);
    fclose(file);
    printf("User data loaded successfully.\n");
}