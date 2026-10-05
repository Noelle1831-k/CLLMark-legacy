void startQuiz() {
    printf("\nStarting Nature Quiz...\n");
    printf("Question 1: What is the largest mammal on Earth?\n");
    printf("1. Elephant\n");
    printf("2. Blue Whale\n");
    printf("3. Giraffe\n");
    printf("Enter your answer: ");
    int answer;
    if (scanf("%d", &answer) != 1) {
        printf("Invalid input. Returning to main menu.\n");
        while (getchar() != '\n'); 
        return;
    }
    if (answer == 2) {
        printf("Correct! The Blue Whale is the largest mammal on Earth.\n");
    } else {
        printf("Incorrect. The correct answer is Blue Whale.\n");
    }
}