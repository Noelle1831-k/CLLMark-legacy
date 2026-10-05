void join_stream(Follower *follower, Livestream *stream) {
    if (follower == NULL || stream == NULL) return;
    printf("%s joined the stream '%s'.\n", follower->name, stream->title);
}