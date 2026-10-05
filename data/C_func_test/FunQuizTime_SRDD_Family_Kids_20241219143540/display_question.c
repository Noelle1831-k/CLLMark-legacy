void display_question(const Question *question, int index) {
    printf("\nQuestion %d: %s\n", index, question->text);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, question->options[i]);
    }
}