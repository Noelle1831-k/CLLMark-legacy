void updateTrack(Track* track) {
    track->currentSegment++;
    if (track->currentSegment > track->totalSegments) {
        track->currentSegment = 0;
    }
}