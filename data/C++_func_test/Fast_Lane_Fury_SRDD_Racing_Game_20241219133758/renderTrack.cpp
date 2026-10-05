void Track::renderTrack() {
    for (const auto& segment : trackLayout) {
        cout << segment << " -> ";
    }
    printf("\n");
}