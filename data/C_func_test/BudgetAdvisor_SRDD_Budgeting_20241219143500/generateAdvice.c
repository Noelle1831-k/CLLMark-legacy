void generateAdvice(User *user) {
    printf("Generating financial advice...\n");
    if (user->income > user->expenses) {
        printf("Great job! You're saving money.\n");
    } else {
        printf("Consider reducing your expenses.\n");
    }
}