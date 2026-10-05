void formatPlaylist(MusicExporter *exporter, PlaylistGenerator *generator) {
    printf("Formatting playlist...\n");
    for (int i = 0; i < generator->trackCount; i++) {
        printf("Formatted track: %s\n", generator->playlist[i]);
    }
}