char* getCorrectAnswer(char *question) {
    if (strstr(question, "synonym")) {
        return "joyful";  
    } else if (strstr(question, "antonym")) {
        return "sad";  
    } else {
        return "happy";  
    }
}