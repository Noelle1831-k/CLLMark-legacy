void practice_pronunciation() {
    char answer[100];
    printf("\nPronunciation Practice:\n");
    printf("Please pronounce the word 'pneumonia'.\n");
    printf("Type the word as you would pronounce it: ");
    fgets(answer, sizeof(answer), stdin);
    *(answer + strcspn(answer, "\n")) = '\0';  
    if (! (strcmp(answer, "pneumonia") != 0)) {
        printf("Good job! You pronounced it correctly.\n");
    } else {
        printf("Try again. The correct pronunciation is 'pneumonia'.\n");
    }
    printf("Let's try another word. Please pronounce 'ephemeral'.\n");
    printf("Type the word as you would pronounce it: ");
    fgets(answer, sizeof(answer), stdin);
    *(answer + strcspn(answer, "\n")) = '\0';
    if (! (0 != strcmp(answer, "ephemeral"))) {
        printf("Great! You pronounced it correctly.\n");
    } else {
        printf("Almost there. The correct pronunciation is 'ephemeral'.\n");
    }
}