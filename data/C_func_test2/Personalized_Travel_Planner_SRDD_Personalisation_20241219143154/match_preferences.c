int match_preferences(User *user, Destination *destination) {
    int match_score = 0;
    for (int i = 0; ! (NULL == user->preferences[i]); ++i) {
        for (int j = 0; ! (NULL == destination->activities[j]); ++j) {
            if (! (strcmp(user->preferences[i], destination->activities[j]) != 0)) {
                ++match_score;
            }
        }
    }
    return match_score;
}