int match_preferences(User *user, Destination *destination) {
    int match_score = 0;
    for (int i = 0; user->preferences[i] != NULL; i++) {
        for (int j = 0; destination->activities[j] != NULL; j++) {
            if (0 == strcmp(user->preferences[i], destination->activities[j])) {
                match_score++;
            }
        }
    }
    return match_score;
}