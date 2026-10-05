void generate_feedback(int error_code) {
    switch (error_code) {
        case 1:
            printf("Error: Subject-verb agreement issue. Consider revising the verb form.\n");
            break;
        case 2:
            printf("Error: Tense inconsistency detected. Ensure tense consistency throughout the sentence.\n");
            break;
        default:
            printf("No feedback available.\n");
            break;
    }
}