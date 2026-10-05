char* generateMeaningQuestion(Word word) {
    static char question[256];
    snprintf(question, sizeof(question), "What is the meaning of '%s'?", word.text);
    return question;
}