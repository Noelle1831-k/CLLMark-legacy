void free_livestream(Livestream *stream) {
    if (stream != NULL) {
        printf("Freeing livestream: %s (ID: %d)\n", stream->title, stream->id);
        free(stream);
    }
}