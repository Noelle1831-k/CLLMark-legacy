void leave_stream(Follower *follower, Livestream *stream) {
    if (follower == NULL || stream == NULL) return;
    printf("%s left the stream '%s'.\n", follower->name, stream->title);
}