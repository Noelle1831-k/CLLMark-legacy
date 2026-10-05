void start_quiz(const char *language, int difficulty) {
    char user_input[50];
    char *correct_word;
    int score = 0;
    int max_questions = 10;
    printf("Starting quiz in %s at difficulty level %d...\n", language, difficulty);
    for (int i = 0; i < max_questions; i++) {
        correct_word = get_word(difficulty);
        if (!correct_word) {
            printf("No words available for the selected difficulty.\n");
            break;
        }
        printf("Spell the word: %s\n", correct_word);
        if (scanf("%s", user_input) != 1) {
            printf("Invalid input. Please enter a valid word.\n");
            while(getchar() != '\n');  
            i--;  
            continue;
        }
        if (check_spelling(user_input, correct_word)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct spelling is: %s\n", correct_word);
        }
    }
    printf("Quiz completed. Your score: %d/%d\n", score, max_questions);
    save_progress(language, difficulty, score);
}