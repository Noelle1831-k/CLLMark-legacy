void generateRecommendations(UserData *user) {
    printf("\nPersonalized Recommendations:\n");
    if (user->weight > 0 && user->height > 0) {
        double bmi = calculateBMI(user->weight, user->height);
        printf("Your BMI is: %.2f\n", bmi);
        if (bmi < 18.5) {
            printf("You are underweight. Consider increasing your calorie intake.\n");
        } else if (bmi < 24.9) {
            printf("You have a normal weight. Maintain your current lifestyle.\n");
        } else {
            printf("You are overweight. Consider a balanced diet and regular exercise.\n");
        }
        suggestExercise(user->activityLevel);
        suggestDiet(user->caloriesIntake, user->age, user->gender);
    } else {
        printf("Please input your weight and height to get recommendations.\n");
    }
}