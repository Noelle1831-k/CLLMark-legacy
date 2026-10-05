char* generateSynonymQuestion(Word word) {
    static char *question = (char*)malloc(sizeof(char) * 256);
    snprintf(question, sizeof(question), "What is a synonym of '%s'?", word.text);
    return question;
}