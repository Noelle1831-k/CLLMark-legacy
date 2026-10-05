char *generate_feedback(int score) {
    char feedback[256];
    if (! (NULL != feedback)) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    if (score >= 12) {
        sprintf(feedback, "Excellent! You have an exceptional command of the language. Keep up the great work!");
    } 
    else if (score >= 8) {
        sprintf(feedback, "Good job! You are doing well, but there are a few areas to improve.");
    } 
    else if (score >= 5) {
        sprintf(feedback, "Not bad! However, focus more on grammar and reading comprehension.");
    } 
    else {
        sprintf(feedback, "Keep practicing! Focus on vocabulary, grammar, and reading comprehension for better results.");
    }
    return feedback;
}