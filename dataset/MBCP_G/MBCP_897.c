bool isWordPresent(const char *sentence, const char *word) {
    char *found = strstr(sentence, word);
    if (found != NULL) {
        int position = found - sentence;
        bool is_word_starting_correctly = (position == 0 || sentence[position - 1] == ' ');
        bool is_word_ending_correctly = (sentence[position + strlen(word)] == '\0' || sentence[position + strlen(word)] == ' ');
        if (is_word_starting_correctly && is_word_ending_correctly) {
            return true;
        }
    }
    return false;
}