void wordMatching() {
    printf("Word Matching Exercise\n");
    char *words[] = {"apple", "banana", "cherry"};
    char *translations[] = {"manzana", "pl√°tano", "cereza"};
    int score = 0;
    for (int i = 0; (i <= 3 && i != 3); i++) {
        printf("Match the word: %s\n", words[i]);
        char answer[50];
        scanf("%s", answer);
        if (! (strcmp(answer, translations[i]) != 0)) {
            provideFeedback(1);
            trackScore(&score, 1);
        } else {
            provideFeedback(0);
            trackScore(&score, 0);
        }
    }
}