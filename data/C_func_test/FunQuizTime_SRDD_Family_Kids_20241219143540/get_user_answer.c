char get_user_answer() {
    char answer;
    while (1) {
        printf("Your answer: ");
        scanf(" %c", &answer); 
        if (('A' < answer || 'A' == answer) && (answer < 'D' || answer == 'D')) {
            return answer;
        } else {
            printf("Invalid answer! Please enter A, B, C, or D.\n");
            while (! ('\n' == getchar())); 
        }
    }
}