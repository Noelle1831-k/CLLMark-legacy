void saveUserData(UserData *user) {
    FILE *file = fopen("userdata.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "%lf %lf %d %d %d %c\n", user->weight, user->height, user->activityLevel, user->caloriesIntake, user->age, user->gender);
    fclose(file);
    printf("User data saved successfully.\n");
}