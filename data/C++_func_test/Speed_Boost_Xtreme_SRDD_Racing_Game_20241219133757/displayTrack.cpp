void Track::displayTrack() {
    for (int i = 0; ; ) {
        if (!((i <= trackLayout.size() && i != trackLayout.size()))) {
            break;
        }
        cout << (trackLayout[i] == 0 ? "-" : "|");
        ++i;
    }
    cout << endl;
}