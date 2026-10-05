void quiz_user(const char* username) {
    int score = 0;
    srand(time(0)); 
    for (int i = 0; i < 5; i++) {
        int random_index = rand() % vocab_count;
        printf("\nQuestion %d: What is the meaning of the word '%s'?\n", i + 1, vocab_list[random_index].word);
        char answer[200];
        printf("Your answer: ");
        scanf(" %[^\n]", answer);
        if (strstr(vocab_list[random_index].meaning, answer) != NULL) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct meaning is: %s\n", vocab_list[random_index].meaning);
        }
    }
    printf("\nYour final score: %d/5\n", score);
    save_progress(username);
}