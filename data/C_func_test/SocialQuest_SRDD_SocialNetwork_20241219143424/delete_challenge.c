void delete_challenge(Challenge *challenge) {
    free(challenge->description);
    free(challenge);
}