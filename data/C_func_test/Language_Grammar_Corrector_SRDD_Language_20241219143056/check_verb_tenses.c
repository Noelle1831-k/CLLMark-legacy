int check_verb_tenses(char* sentence) {
    if (strstr(sentence, "was") && strstr(sentence, "am")) {
        return 2; 
    }
    return 0;
}