void inputUserData(UserData *user) {
    printf("Enter your weight (kg): ");
    scanf("%lf", &user->weight);
    printf("Enter your height (cm): ");
    scanf("%lf", &user->height);
    printf("Enter your daily activity level (1-5): ");
    scanf("%d", &user->activityLevel);
    printf("Enter your daily calories intake: ");
    scanf("%d", &user->caloriesIntake);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &user->gender);
}