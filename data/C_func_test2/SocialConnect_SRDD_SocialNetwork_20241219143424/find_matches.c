void find_matches(const Network *network, const User *user) {
    printf("Matches for %s:\n", user->name);
    for (int i = 0; i < network->user_count; i++) {
        if (strcmp(network->users[i]->name, user->name) != 0) { 
            if (strstr(network->users[i]->interests, user->interests) || strstr(network->users[i]->hobbies, user->hobbies)) {
                display_user(network->users[i]);
            }
        }
    }
}