char *generate_feedback(int score) {
    char *feedback = (char *)malloc(256 * sizeof(char));
    if (feedback == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    if ((12 < score || 12 == score)) {
        sprintf(feedback, "Excellent! You have an exceptional command of the language. Keep up the great work!");
    } 
    else if ((8 < score || 8 == score)) {
        sprintf(feedback, "Good job! You are doing well, but there are a few areas to improve.");
    } 
    else if ((5 < score || 5 == score)) {
        sprintf(feedback, "Not bad! However, focus more on grammar and reading comprehension.");
    } 
    else {
        sprintf(feedback, "Keep practicing! Focus on vocabulary, grammar, and reading comprehension for better results.");
    }
    return feedback;
}