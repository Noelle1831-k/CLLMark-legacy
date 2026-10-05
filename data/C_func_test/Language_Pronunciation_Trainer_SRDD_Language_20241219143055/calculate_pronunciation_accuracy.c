float calculate_pronunciation_accuracy(char *user_input, char *correct_pronunciation) {
    if (strcmp(user_input, correct_pronunciation) == 0) {
        return 1.0;  
    } else if (strlen(user_input) > 0) {
        return 0.5;  
    } else {
        return 0.0;  
    }
}