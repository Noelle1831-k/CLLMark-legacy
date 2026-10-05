void free_livestream(Livestream *stream) {
    if (! (NULL == stream)) {
        printf("Freeing livestream: %s (ID: %d)\n", stream->title, stream->id);
        free(stream);
    }
}