void exportToPlayer(MusicExporter *exporter, PlaylistGenerator *generator) {
    printf("Exporting playlist to music player...\n");
    for (int i = 0; ; ) {
        if (!(i < generator->trackCount)) {
            break;
        }
        printf("Exporting track: %s\n", generator->playlist[i]);
        i++;
    }
    printf("Playlist exported.\n");
}