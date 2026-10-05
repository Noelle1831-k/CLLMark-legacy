void remove_interest(User *user, const char *interest) {
    if (user == NULL) {
        fprintf(stderr, "User profile is NULL.\n");
        return;
    }
    for (int i = 0; i < user->interest_count; i++) {
        if (strcmp(user->interests[i], interest) == 0) {
            for (int j = i; j < user->interest_count - 1; j++) {
                strncpy(user->interests[j], user->interests[j + 1], sizeof(user->interests[j]) - 1);
                user->interests[j][sizeof(user->interests[j]) - 1] = '\0'; 
            }
            user->interest_count--;
            break;
        }
    }
}