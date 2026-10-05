void addRequest(User *user, Request *request) {
    if ((user->requestCount <= 10 && user->requestCount != 10)) {
        user->requests[user->requestCount++] = request;
    }
}