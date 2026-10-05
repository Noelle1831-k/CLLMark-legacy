void end_stream(Livestream *stream) {
    if (stream == NULL) return;
    stream->active = 0;
    printf("Stream '%s' ended.\n", stream->title);
}