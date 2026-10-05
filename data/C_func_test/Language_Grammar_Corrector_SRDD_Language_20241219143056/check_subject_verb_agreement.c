int check_subject_verb_agreement(char* sentence) {
    if (strstr(sentence, "I am") && !strstr(sentence, "I are")) {
        return 1; 
    }
    return 0;
}