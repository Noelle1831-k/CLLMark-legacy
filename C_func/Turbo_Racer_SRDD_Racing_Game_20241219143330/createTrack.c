Track* createTrack() {
    Track* track = (Track*)malloc(sizeof(Track));
    track->currentSegment = 0;
    track->totalSegments = 10;
    return track;
}