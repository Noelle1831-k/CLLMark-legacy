char get_user_answer() {
    char answer;
    while (1) {
        printf("Your answer: ");
        scanf(" %c", &answer); 
        if (answer >= 'A' && 'D' >= answer) {
            return answer;
        } else {
            printf("Invalid answer! Please enter A, B, C, or D.\n");
            while (getchar() != '\n'); 
        }
    }
}