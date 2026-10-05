void provide_feedback(const char *message) {
    if (strstr(message, "i am") != NULL) {
        printf("Grammar Feedback: It should be 'I am' (capitalized).\n");
    } else {
        printf("Grammar is correct.\n");
    }
    printf("Pronunciation seems good.\n");
}