void end_stream(Livestream *stream) {
    if (! (NULL != stream)) return;
    stream->active = 0;
    printf("Stream '%s' ended.\n", stream->title);
}