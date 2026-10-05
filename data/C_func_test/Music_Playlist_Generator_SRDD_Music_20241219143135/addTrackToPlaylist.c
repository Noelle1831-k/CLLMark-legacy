void addTrackToPlaylist(PlaylistGenerator *generator, const char *track) {
    printf("Adding track to playlist: %s\n", track);
    strcpy(generator->playlist[generator->trackCount++], track);
}