void takeQuiz() {
    int answer;
    int score = 0;
    printf("Welcome to the GardenTime Quiz!\n");
    printf("Question 1: What is the best time to plant most vegetables?\n");
    printf("1. Morning\n2. Afternoon\n3. Evening\n");
    printf("Enter your answer (1-3): ");
    scanf("%d", &answer);
    if (answer == 1) {
        score++;
    }
    printf("Question 2: How often should you water a Rose plant?\n");
    printf("1. Every 2 days\n2. Every 5 days\n3. Once a week\n");
    printf("Enter your answer (1-3): ");
    scanf("%d", &answer);
    if (answer == 1) {
        score++;
    }
    printf("You scored %d out of 2.\n", score);
}