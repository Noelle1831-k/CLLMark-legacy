void Track::displayTrack() {
    for (int i = 0; i < trackLayout.size(); i++) {
        cout << (trackLayout[i] == 0 ? "-" : "|");
    }
    cout << endl;
}