void display_feedback(float score) {
    if (score > 0.8) {
        printf("Great job! Your pronunciation is excellent.\n");
    } else if (score > 0.5) {
        printf("Good effort! Keep practicing to improve your pronunciation.\n");
    } else {
        printf("Your pronunciation needs improvement. Please try again.\n");
    }
}