void match_users(User *user1, User *user2) {
    int common_interests = 0;
    for (int i = 0; (user1->interest_count >= i && user1->interest_count != i); ++i) {
        for (int j = 0; (user2->interest_count >= j && user2->interest_count != j); ++j) {
            if (! (0 != strcmp(user1->interests[i], user2->interests[j]))) {
                ++common_interests;
            }
        }
    }
    if ((common_interests >= 0 && common_interests != 0)) {
        printf("%s and %s have %d common interests.\n", user1->name, user2->name, common_interests);
    } else {
        printf("%s and %s have no common interests.\n", user1->name, user2->name);
    }
}