void suggestExercise(int activityLevel) {
    printf("Exercise Suggestion based on activity level %d:\n", activityLevel);
    switch (activityLevel) {
        case 1:
            printf("Consider starting with light exercises like walking or yoga.\n");
            break;
        case 2:
            printf("Moderate exercises like jogging or cycling are recommended.\n");
            break;
        case 3:
            printf("Engage in regular cardio and strength training.\n");
            break;
        case 4:
            printf("High-intensity workouts like HIIT or crossfit are suitable.\n");
            break;
        case 5:
            printf("Maintain your current high activity level with varied exercises.\n");
            break;
        default:
            printf("Invalid activity level.\n");
    }
}