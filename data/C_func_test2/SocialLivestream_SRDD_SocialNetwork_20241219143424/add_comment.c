void add_comment(Livestream *stream, User *user, const char *comment) {
    if (stream == NULL || user == NULL) return;
    printf("[%s] %s: %s\n", stream->title, user->name, comment);
}