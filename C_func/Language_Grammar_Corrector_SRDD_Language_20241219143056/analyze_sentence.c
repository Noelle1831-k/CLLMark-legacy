int analyze_sentence(char* sentence) {
    int error_code = 0;
    error_code = check_subject_verb_agreement(sentence);
    if (error_code) return error_code;
    error_code = check_verb_tenses(sentence);
    if (error_code) return error_code;
    return 0; 
}