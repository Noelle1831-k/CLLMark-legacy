Livestream* start_stream(User *user, const char *title) {
    if (user == NULL) return NULL;
    Livestream *stream = (Livestream *)malloc(sizeof(Livestream));
    if (stream == NULL) {
        fprintf(stderr, "Memory allocation failed for livestream.\n");
        return NULL;
    }
    stream->id = generate_unique_id();
    stream->user_id = user->id;
    strncpy(stream->title, title, sizeof(stream->title) - 1);
    stream->active = 1;
    printf("Stream '%s' started by %s.\n", stream->title, user->name);
    return stream;
}