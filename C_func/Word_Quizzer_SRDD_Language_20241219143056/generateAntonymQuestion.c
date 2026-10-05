char* generateAntonymQuestion(Word word) {
    static char question[256];
    snprintf(question, sizeof(question), "What is an antonym of '%s'?", word.text);
    return question;
}