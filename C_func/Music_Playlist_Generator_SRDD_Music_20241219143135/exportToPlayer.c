void exportToPlayer(MusicExporter *exporter, PlaylistGenerator *generator) {
    printf("Exporting playlist to music player...\n");
    for (int i = 0; i < generator->trackCount; i++) {
        printf("Exporting track: %s\n", generator->playlist[i]);
    }
    printf("Playlist exported.\n");
}