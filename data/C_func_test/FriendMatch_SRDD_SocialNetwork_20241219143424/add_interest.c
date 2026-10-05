void add_interest(User *user, const char *interest) {
    if (user == NULL) {
        fprintf(stderr, "User profile is NULL.\n");
        return;
    }
    if (user->interest_count < 10) {
        strncpy(user->interests[user->interest_count], interest, sizeof(user->interests[user->interest_count]) - 1);
        user->interests[user->interest_count][sizeof(user->interests[user->interest_count]) - 1] = '\0'; 
        user->interest_count++;
    } else {
        fprintf(stderr, "Maximum number of interests reached for user %s.\n", user->name);
    }
}