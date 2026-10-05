void practice_scales() {
    int difficulty;
    char user_input[50];
    int correct = 0;
    printf("\nChoose difficulty (1: Easy, 2: Medium, 3: Hard): ");
    scanf("%d", &difficulty);
    for (int i = 0; i < 5; i++) {
        printf("Identify the scale: %s\n", scales[random_index()]);
        printf("Your Answer: ");
        scanf("%s", user_input);
        if (strcmp(user_input, scales[i]) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer was %s\n", scales[i]);
        }
    }
    printf("You answered %d/5 correctly.\n", correct);
}