void speech_to_text(char *output) {
    printf("STT: Simulated user feedback. Please enter your feedback: ");
    fgets(output, 256, stdin);
    *(output + strcspn(output, "\n")) = '\0'; 
}