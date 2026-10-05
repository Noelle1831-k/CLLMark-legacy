void Track::generateTrack() {
    trackLayout.clear();
    int i;
    for (i = 0; i < 50; ++i) {
        trackLayout.push_back(rand() % 2);
    }
}