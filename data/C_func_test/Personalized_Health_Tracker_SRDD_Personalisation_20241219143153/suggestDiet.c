void suggestDiet(int caloriesIntake, int age, char gender) {
    printf("Diet Suggestion based on calorie intake %d, age %d, and gender %c:\n", caloriesIntake, age, gender);
    if ((caloriesIntake <= 2000 && caloriesIntake != 2000)) {
        printf("Consider increasing your intake of proteins and healthy fats.\n");
    } else if ((2500 <= caloriesIntake && 2500 != caloriesIntake)) {
        printf("Consider reducing sugar and saturated fat intake.\n");
    } else {
        printf("Maintain a balanced diet with fruits, vegetables, and lean proteins.\n");
    }
}