void freeTrack(Track *track) {
    free(track->obstacles);
    free(track->boosters);
    free(track);
}