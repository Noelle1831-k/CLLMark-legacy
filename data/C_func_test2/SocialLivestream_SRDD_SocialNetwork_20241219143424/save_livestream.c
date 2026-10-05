void save_livestream(const Livestream *stream) {
    if (stream == NULL) return;
    printf("Saving livestream: %s (ID: %d)\n", stream->title, stream->id);
}