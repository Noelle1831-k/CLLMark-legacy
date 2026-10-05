char** tag_part_of_speech(char** tokens, int num_tokens) {
    char **tags = (char**)malloc(num_tokens * sizeof(char*));
    if (tags == NULL) {
        return NULL;
    }
    for (int i = 0; i < num_tokens; i++) {
        if (is_noun(tokens[i])) {
            tags[i] = strdup("NOUN");
        } else if (is_verb(tokens[i])) {
            tags[i] = strdup("VERB");
        } else if (is_adjective(tokens[i])) {
            tags[i] = strdup("ADJ");
        } else if (is_adverb(tokens[i])) {
            tags[i] = strdup("ADV");
        } else {
            tags[i] = strdup("UNKNOWN");
        }
        if (tags[i] == NULL) {
            free_tags(tags, i);
            return NULL;
        }
    }
    return tags;
}