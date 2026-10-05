void provide_feedback(int score) {
    if (score == 2) {
        printf("Excellent! You got all the questions right.\n");
    } else if (score == 1) {
        printf("Good job! You got one question right.\n");
    } else {
        printf("Keep trying! You can improve with more practice.\n");
    }
}