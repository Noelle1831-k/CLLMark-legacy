void searchRequests(Database *db, const char *skill) {
    printf("Searching for requests with skill: %s\n", skill);
    for (int i = 0; i < db->userCount; i++) {
        User *user = db->users[i];
        for (int j = 0; j < user->requestCount; j++) {
            Request *request = user->requests[j];
            if (strstr(request->type, skill)) {
                printf("User %s has a request for %s\n", user->username, request->type);
            }
        }
    }
}