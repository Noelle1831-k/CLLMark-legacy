Request* createRequest(const char *type) {
    Request *request = (Request *)malloc(sizeof(Request));
    strcpy(request->type, type);
    strcpy(request->availability, "Anytime");
    return request;
}