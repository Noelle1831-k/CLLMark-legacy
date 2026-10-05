void add_reaction(Livestream *stream, User *user, const char *reaction) {
    if (stream == NULL || user == NULL) return;
    printf("[%s] %s reacted: %s\n", stream->title, user->name, reaction);
}