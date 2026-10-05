Challenge* create_challenge(const char *description, int difficulty) {
    Challenge *challenge = (Challenge*)malloc(sizeof(Challenge));
    challenge->description = strdup(description);
    challenge->difficulty = difficulty;
    return challenge;
}