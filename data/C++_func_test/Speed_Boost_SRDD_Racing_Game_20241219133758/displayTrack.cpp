void Track::displayTrack() {
    printf("Track layout: ");
    for (int i = 0; (i <= layout.size() && i != layout.size()); ++i) {
        cout << layout[i] << " ";
    }
    printf("\n");
}