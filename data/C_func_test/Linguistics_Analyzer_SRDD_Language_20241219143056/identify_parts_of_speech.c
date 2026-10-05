char* identify_parts_of_speech(char *word) {
    to_lowercase(word);
    if (strcmp(word, "the") == 0 || strcmp(word, "a") == 0 || strcmp(word, "an") == 0) {
        return "Article";
    } else if (strcmp(word, "is") == 0 || strcmp(word, "are") == 0 || strcmp(word, "was") == 0 || strcmp(word, "were") == 0) {
        return "Verb";
    } else if (strcmp(word, "and") == 0 || strcmp(word, "but") == 0 || strcmp(word, "or") == 0) {
        return "Conjunction";
    } else if (strcmp(word, "quickly") == 0 || strcmp(word, "slowly") == 0) {
        return "Adverb";
    } else if (strcmp(word, "happy") == 0 || strcmp(word, "sad") == 0) {
        return "Adjective";
    } else {
        return "Noun";
    }
}