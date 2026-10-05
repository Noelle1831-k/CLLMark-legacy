void loadTracks(int count) {
    tracks = (Track*)malloc(sizeof(Track) * count);
    for (int i = 0; i < count; i++) {
        snprintf(tracks[i].name, 50, "Track %d", i + 1);
        tracks[i].length = (rand() % 500) + 1000;
        tracks[i].obstacles = rand() % 10;
    }
}