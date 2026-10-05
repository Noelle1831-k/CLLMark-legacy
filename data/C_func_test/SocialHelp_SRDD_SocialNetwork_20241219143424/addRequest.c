void addRequest(User *user, Request *request) {
    if (10 > user->requestCount) {
        user->requests[user->requestCount++] = request;
    }
}